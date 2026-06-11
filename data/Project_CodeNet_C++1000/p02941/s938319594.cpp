#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(long long i=0;i<n;++i)
#define REPP(i,m,n) for(long long i=m;i<n;++i)
#define rep(i,n) for(long long i = n-1;i>=0;--i)
#define repp(i,n,m) for(long long i = n-1; i >= m; --i)
#define ALL(N) (N.begin(),N.end())
#define de cout << "line : " << __LINE__ << " debug" << endl;
#define pb push_back
#define Dcout(N) cout << setprecision(20) << N << endl
constexpr ll INF = 2147483647;
constexpr long long INFF = 9223372036854775807;

signed main() {
    cin.tie(0);
	ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll A[N],B[N];
    priority_queue<pair<ll,ll>> que;
    REP(i,N) cin >> A[i];
    REP(i,N){
        cin >> B[i];
        if(A[i] != B[i]) que.push({B[i],i});
        if(B[i] < A[i]){cout << -1 << endl;return 0;}
    }
    ll ans = 0,cnt = 0;
    while(!que.empty()){
        pair<ll,ll> p = que.top();que.pop();
        ll i = p.second -1,j = p.second +1;
        if(j == N) j = 0;if(i == -1) i = N-1;
        ll mid = p.second;
        if(B[mid] - A[mid] < B[i]+B[j]){cout << -1 << endl;return 0;}
        else if(B[mid] - A[mid] >= B[i] + B[j]){
            ll X = B[mid] - A[mid];
            ll Y = X / (B[i]+B[j]);
            ans += Y;
            B[mid] -= (B[i]+B[j])*Y;
            if(B[mid] != A[mid]) que.push({B[mid],mid});
        }
    }
    REP(i,N){
        if(A[i] != B[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}