#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,A,B,L;
string S;
string alpha = "abcdefghijklmnopqrstuvwxyz";
string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//const ll MOD = 998244353;
typedef pair<ll,ll> P;

int main() {
    cin>>N;
    vec a(N),b(N);
    rep(i,N) cin>>a[i];
    priority_queue<P> pque;
    rep(i,N) {
        cin>>b[i];
        pque.emplace(b[i],i);
    }
    bool judge = false;
    ll ans = 0;
    while((!judge) && (!pque.empty())){
        P p = pque.top();
        pque.pop();
        if(p.fi > a[p.se]){
            A = p.fi;
            ll nei = (b[(p.se + N - 1) % N] + b[(p.se + 1) % N]);
            M = (a[p.se] >= nei) ? (A - a[p.se])/nei : A/nei;
            M = max(1LL,M);
            A -= M * nei;
            ans += M;
            b[p.se] = A;
            pque.emplace(A,p.se);
            if(A <= 0) judge = true;
        }
    }
    bool bad = false;
    rep(i,pque.size()){
        P p = pque.top();
        pque.pop();
        if(p.fi != a[p.se]) bad = true;
    }
    cout<<(bad ? -1 : ans)<<endl;
}
