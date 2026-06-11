#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define imin INT_MIN
#define imax INT_MAX
int mod =1e9+7;
//~ vector<bool> cats;

//~ ll ans;
//~ ll n,m;
//~ void dfs(vector<vector<int>>& graph,int s,int consCats,int parent){
	//~ if(consCats>m) return;
	//~ if(graph[s].size()==1 && graph[s][0]==parent)
	//~ {
		//~ if(cats[s]) consCats++;
		//~ if(consCats<=m) ans++;
		//~ return;
	//~ }
	//~ if(!cats[s]) consCats=0;
	//~ else consCats++;
	//~ for(auto val:graph[s]){
		//~ if(val!=parent)
		//~ dfs(graph,val,consCats,s);
	//~ }


int main(){
	cin.tie(NULL);
    ios_base::sync_with_stdio();

	string s;
	cin>>s;
	int cnt=0;
	int ans=0;
	rep(i,0,2){
		if(s[i]=='R') cnt++;
		else cnt=0;
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	
	return 0;
}
