#include <bits/stdc++.h>
using namespace std;
# define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main(){
	cin.tie(0);
   	ios::sync_with_stdio(false);
	ll N;
    cin>>N;
    typedef pair<ll,ll> P;
    vector<P> A(N);

    rep(i,N){
        ll a;
        cin>>a;
        A[i] = P{i,a};
    }

    sort(A.begin(),A.end(),[](P p1, P p2){return p1.second>p2.second;});
    
    ll dp[N+1][N+1] = {};
    dp[0][0] = 0;
    rep(i,N){
        ll ind,a;
        ind = A[i].first+1;
        a = A[i].second;

        rep(x,i+1){
            ll y = i-x;
            dp[x+1][y] = max(dp[x+1][y],dp[x][y]+a*(ind-(x+1)));
            dp[x][y+1] = max(dp[x][y+1],dp[x][y]+a*((N-(y-1))-(ind+1)));
        }
    }

    ll ans = 0;
    rep(i,N+1){
        ans = max(ans,dp[i][N-i]);
    }

    cout<<ans<<"\n";
    



	return 0;
}