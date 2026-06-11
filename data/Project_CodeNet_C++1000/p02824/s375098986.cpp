#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B;
string S, T;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;
ll V;
vec a(0);

bool ok(ll c){
    if(c == K - 1) return true;
    ll b = a[c] + M, rest = M * (V - K);
    if(rest <= 0) return b >= a[K-1];
    reps(i,K - 1,N){
        if(i == c) continue;
        rest -= min(M, b - a[i]);
    }
    return rest <= 0 && b >= a[K-1];
}
int main(){
    cin>>N>>M>>V>>K;
    rep(i,N) {
        cin>>A;
        a.push_back(A);
    }
    sort(ALL(a));
    reverse(ALL(a));//降順
    ll lb = K - 1, ub = N;
    while(ub - lb > 1){//境界をにぶたん
        ll cen = (ub + lb) /2;
        (ok(cen) ? lb : ub) = cen;
    }
    ll border = a[lb], ans = 0;
    rep(i,N){
        ans += (a[i] >= border);
    }
    cout<<ans<<endl;
}
