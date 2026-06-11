
#include<bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define mp make_pair
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define MOD 1000000007
#define endl "\n"
bool visited[100005];
typedef long long ll;
using namespace std;
vector<int>adj[100005];
void dfs(int i){
	visited[i]=true;

	for(auto j:adj[i]){
		if(!visited[j])
			dfs(j);
	}
}

int main(){

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ll n, m,a,b; cin>>n>>m;
REP(i,1,m+1){
	cin>>a>>b;
	adj[a].push_back(b);
	adj[b].push_back(a);
}
ll count=0;
REP(i,1,n+1){
	if(!visited[i]){
		dfs(i);
	    count++;}
}

cout<<count-1<<endl;


}	
