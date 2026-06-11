#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;
int n,k;
int a[100005],b[100005];
vector<int> G[100005];
bool visited[100005];//その点を訪れたかどうか記録
ll ans=1;
ll mod=1e9+7;
void dfs(int v,int f,int s){
	visited[v]=true;
	ans*=(k-f-s);
	ans%=mod;
	for(auto p:G[v]){
		if(visited[p])continue;
		dfs(p,1,f);
		f++;
	}
}
int main(){
	cin >> n >>k;
	for(int i=0;i<n-1;i++){
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
		G[a[i]].push_back(b[i]);
		G[b[i]].push_back(a[i]);
	}
	dfs(0,0,0);
	cout << ans%mod << endl;
}