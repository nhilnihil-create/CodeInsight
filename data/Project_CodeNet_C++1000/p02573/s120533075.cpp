/*@author Vipen Loka*/
#include <bits/stdc++.h>
#define endl '\n'
#define ff first
#define ss second
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define deb(x) cout << #x << ':' << x << '\n';

using namespace std;

class Tree{
	int n;
	list<int> *tree;
public:
	int mx=0;
	vector<int> visited;
	Tree(int n){
		this->n=n;
		tree=new list<int>[n];
		visited.assign(n,0);
	}

	void addEdge(int a,int b){
		a--;b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	int dfs_util(int s){
		visited[s]=1;
		int c=1;
		for(auto &x:tree[s]){
			if(visited[x])continue;
			c+=dfs_util(x);
		}

		return c;
	}


	void dfs(int s){
		if(visited[s])return;
		mx=max(mx,dfs_util(s));
	}

};

void solve(){
	int i,j;
	int n,m;
	cin >> n >> m;
	Tree t(n);
	for (int i = 0; i < m; ++i)
	{
		int a,b;cin >> a >> b;
		t.addEdge(a,b);
	}

	for (int i = 0; i < n; ++i)
	{
		t.dfs(i);
	}

	int ans=t.mx;

	printf("%d\n",ans);
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	int T=1;
	// cin >> T;
	while (T--){
		solve();
	}
}
