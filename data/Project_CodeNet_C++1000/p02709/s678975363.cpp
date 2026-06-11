#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
const int MAX_N=2e3;
typedef pair<ll,ll> P;
ll N;
P A[MAX_N];
ll memo[MAX_N][MAX_N];

ll dfs(ll n,ll lft,ll rig){
	if(n==N)return 0;
	if(memo[n][lft]!=-1){
		return memo[n][lft];
	}
	return memo[n][lft]=max(A[n].first*llabs(A[n].second-lft)+dfs(n+1,lft+1,rig),
			A[n].first*llabs(A[n].second-rig)+dfs(n+1,lft,rig-1));
}

int main(){
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin>>N;
	REP(i,N){
		cin>>A[i].first;
		A[i].second=i;
	}
	memset(memo,-1,sizeof(memo));
	sort(A,A+N);
	reverse(A,A+N);
	cout<<dfs(0,0,N-1)<<endl;
}
