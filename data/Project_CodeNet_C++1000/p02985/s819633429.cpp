#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define sigma_size 30
#define max_size (int)(1e6+10)
#define _DEBUG1 freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define _DEBUG2 fclose("input.txt");fclose("output.txt");

const LL MOD = 1E9 + 7;
LL n , k;
struct node
{
	LL num;
	int friends;
	int f;
	vector <int> arc;
}Node[max_size];

void dfs( int x )
{
	if ( Node[x].f == -1 )
		Node[x].num = k;
	else if ( Node[x].f == 1 )
		Node[x].num = k - Node[x].friends - 1;
	else 
		Node[x].num = k - Node[x].friends - 2;
	int tot = 0;
	for ( int i = 0 ; i < Node[x].arc.size() ; i++ )
	{
		int y = Node[x].arc[i];
		if ( y == Node[x].f ) continue;
		Node[y].f = x;
		Node[y].friends = tot++;
		dfs(y);
	}
}
int main ()
{
	ios::sync_with_stdio(0);
	cin >> n >> k;
	for ( int i = 1 ; i < n ; i++ )
	{
		int u , v;
		cin >> u >> v;
		Node[u].arc.push_back(v);
		Node[v].arc.push_back(u);
	}
	Node[1].f = -1;
	dfs(1);
	LL res = 1;
	for ( int i = 1 ; i <= n ; i++ )
		res = (res * Node[i].num) % MOD;
	cout << res << endl;
}