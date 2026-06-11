#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0;i<n;i++)
#define REP(i,a,n) for(ll i=a;i<n;i++)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
typedef pair<ll, ll> pll;

const int INF = 100000000;
const ll LINF = 1e18+5;

int main() {
    ll N;
    cin >> N;
    ll A[300000] = {};
    rep(i,N){
        ll a;
        cin >> a;
        A[a-1]++;
    }
    vector<ll> S;
    rep(i, 300000) {
        if(A[i]!=0) S.push_back(A[i]);
    }
    sort(S.begin(), S.end());
    vector<ll> D(N+1);
    rep(i,S.size()){
        D[S[i]]++;
    }
    vector<ll> Ds(N+1, 0);
    REP(i,1, N+1){
        Ds[i] = Ds[i-1] + D[i];
    }
    vector<ll> kDs(N+1, 0);
    REP(i, 1, N+1){
        kDs[i] = kDs[i-1] + i * D[i];
    }

    vector<ll> f(N+1);
    REP(i,1,N+1){
        f[i] = (kDs[i] + i * (Ds[N] - Ds[i])) / i;
    }
    vector<ll> ans(N+1);
    ll pos = N;
    REP(i, 1, N+1){
        while(i>f[pos] && pos!=0) pos--;
        cout << pos << endl;
    }

    return 0;
}