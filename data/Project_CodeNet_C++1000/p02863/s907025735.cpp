#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define TO_STRING(VariableName) # VariableName
#define LOG(x) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" ";
#define LOGE if(DEBUG)cout<<endl;

template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

lli dp[7000];

int main(){

	lli n,t;
	cin>>n>>t;

	///REP(i,0,4000)REP(j,0,7000)dp[i][j]=-INF;

	vector<pair<lli,lli>> v;
	REP(i,0,n){
		lli a,b;
		cin>>a>>b;
		v.push_back({a,b});
	}
	sort(v.begin(),v.end());

	REP(i,0,n){
		lli a = v[i].first;
		lli b = v[i].second;
		for(lli j=t-1;j>=0;j--){
			chmax(dp[j+a],dp[j]+b);
		}
	}

	lli ans = 0;
	REP(i,0,7000){
		chmax(ans,dp[i]);
	}
	cout<<ans<<endl;

    return 0;
}
