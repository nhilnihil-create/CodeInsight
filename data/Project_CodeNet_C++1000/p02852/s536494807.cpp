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

#define P pair<lli,lli>

lli dp[200100];
bool flag;
bool vis[200100];
lli n,m;
string s;

void func(lli now){
	if(now>n)return;
	if(DEBUG)cout<<"now="<<now<<"s.at(now="<<s.at(now)<<endl;
	if(s.at(now)=='1')return;
	if(vis[now])return;
	if(now==n){
		flag = true;
		return;
	}
	vis[now]=true;
	for(lli i=m;i>=1;i--){
		func(now+i);
		if(flag){
			cout<<i<<" ";
			return;
		}
	}
}

signed main(){

	cin>>n>>m;
	cin>>s;
	reverse(s.begin(),s.end());

	func(0);
	if(!flag){
		cout<<-1<<endl;
	}
	else cout<<endl;

	return 0;
}