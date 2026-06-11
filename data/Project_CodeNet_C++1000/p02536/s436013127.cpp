#include<bits/stdc++.h>
#define fo(i,a,b) for(int i= a ; i < b ; ++i)
#define rep(i,n) fo(i,0,n)
#define pln(n) printf("%lld",n)
#define sll(n) scanf("%lld",&n)
#define ss(n) scanf("%s",n)
#define vi vector < int >
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
#define dbg3(x,y,z) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) <<" , "<< #z <<": "<<(z)<<endl; }
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<ll>>>
#define si set<int>
#define tr(c, it) \
for(decltype(c.begin()) it = c.begin(); it!= c.end(); it++)
#define pis pair<int,string>
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c),x) != c.end())
#define  ones(x)  __builtin_popcount(x)
using namespace std;
vector<int> adj[100010];

void dfs(int i, vector<int> & vis){
	vis[i] = true;
	for(int ch: adj[i]){
		if(!vis[ch]){
			dfs(ch, vis);
		}
	}
}
int main(){
//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	int m;
	cin >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int ans = 0;
	vector<int> vis(n+1,0);
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
			dfs(i, vis);
			ans++;
		}
	}
	cout << ans-1 << endl;
}
