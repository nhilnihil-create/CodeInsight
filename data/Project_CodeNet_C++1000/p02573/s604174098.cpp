#include<bits/stdc++.h>
#define fo(i,a,b) for(int i= a ; i < b ; ++i)
#define rep(i,n) fo(i,0,n)
#define pln(n) printf("%lld\n",n)
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
#define vvi vector<vector<int>>
#define si set<int>
#define tr(c, it) \
for(decltype(c.begin()) it = c.begin(); it!= c.end(); it++)
#define pis pair<int,string>
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c),x) != c.end())
#define mod (int)(1e9 + 7) 
using namespace std;

void dfs(vector<int> g[],int i, int& c, vector<int>& vis){
	vis[i] = 1;
	c++;
	for(int ch: g[i]){
		if(vis[ch] == -1){
			dfs(g, ch, c, vis);
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> g[n+1];
	for(int i = 1; i <= m; i++){
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int> group;
	vector<int> vis(n+1, -1);
	for(int i = 1; i <= n; i++){
		if(vis[i] == -1){
			int c = 0;
			dfs(g, i, c, vis);
			group.push_back(c);
		}
	}
	cout << *max_element(group.begin(), group.end());
	// int ans = 0;
	// while(1){
	// 	int f = 0;
	// 	for(int& x: group){
	// 		if(x > 0){
	// 			x--;
	// 			f = 1;
	// 		}
	// 	}
	// 	if(!f)break;
	// 	ans++;
	// }
	// cout << ans;
	
	// for(int i = 1; i <= n; i++){
	// 	for(int x: g[i]){
	// 		cout << x <<" ";
	// 	}cout << endl;
	// }
}
