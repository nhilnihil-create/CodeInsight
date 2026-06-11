#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,m;
string s;
V<int> can,ans;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>n>>m;
	cin>>s;
	FOR(i,0,n){
		if(s[i]=='0')can.PB(i);
	}
	if(s[0]=='1'||s[n]=='1'){
		cout<<-1;RE 0;
	}
	rep(i,1,can.size()){
		if(can[i]-can[i-1]>m){
			cout<<-1;RE 0;
		}
	}
	int now=n;ans.PB(now);
	while(now){
		now=*lower_bound(ALL(can),now-m);ans.PB(now);
	}
//	rep(i,0,ans.size())cout<<ans[i]<<' ';cout<<'\n';
	for(int i=ans.size()-1;i>=1;i--)cout<<ans[i-1]-ans[i]<<' '; 
	RE 0;
}



