#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define INF (1LL<<50)

lli n,m;
bool ok;
string s;
bool vis[100100];

void func(lli now){
	if(DEBUG)cout<<"now="<<now<<endl;
	if(now>n)return;
	if(now==n){
		ok=true;
		return;
	}
	if(s.at(now)=='1')return;
	if(vis[now])return;
	vis[now]=true;

	for(lli i=m;i>0;i--){
		func(now+i);
		if(ok){
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
	if(!ok){
		cout<<-1<<endl;
		return 0 ;
	}

	return 0;
}