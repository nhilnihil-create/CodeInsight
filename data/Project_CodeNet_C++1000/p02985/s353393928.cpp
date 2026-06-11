#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)

map<lli,vector<lli>> d;
bool vis[100100];
lli dp[100100];
lli k;

void func(lli now,lli depth,lli num){
	if(vis[now])return;
	if(DEBUG)cout<<"now="<<now<<endl;
	dp[now] = num;
	vis[now] = true;
	if(DEBUG)cout<<"dp[now]="<<dp[now]<<endl;
	lli nextNum = k;
	if(depth==0)nextNum--;
	else nextNum-=2;
	for(auto e:d[now]){
		if(vis[e])continue;
		func(e,depth+1,nextNum);
		nextNum = max(0LL,nextNum-1);
	}
}

signed main(){

	lli n;
	cin>>n>>k;
	REP(i,0,n-1){
		lli a,b;
		cin>>a>>b;
		a--,b--;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	func(0,0,k);

	lli sum = 1;
	REP(i,0,n){
		sum *= dp[i];
		sum %= MOD;
	}
	cout<<sum<<endl;

	return 0;
}