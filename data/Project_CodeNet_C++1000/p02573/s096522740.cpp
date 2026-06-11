#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define mt make_tuple
#define MOD 1000000007
#define fo(i,a,b) for(i=a;i<b;i++)
#define foe(i,a,b) for(i=a;i<=b;i++)
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vl vector <long long int>
#define pii pair <int,int>
#define pll pair <long long int, long long int>
#define vpii vector< pair<int,int> >
#define vpll vector < pair <long long int,long long int> >
#define boost ios::sync_with_stdio(false); cin.tie(0)
using namespace std;
const int inf = 1e9 + 5;
const ll inf64 = 1e18 + 5;

const int MAX = 2e5 + 5;
int par[MAX], sz[MAX];
void init(int n) {
	for(int i = 0; i <= n; i++) {
		par[i] = i;
		sz[i] = 1;
	}
}
int find_parent(int a)
{
	if(a == par[a]) return a;
	return par[a] = find_parent(par[a]);
}
void union_sets(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);
	if(a != b) {
		if(sz[a] < sz[b])
			swap(a, b);
		par[b] = a;
		sz[a] += sz[b];
	}
}

int main()
{
	boost;
	int n, m, i, a, b;
	cin >> n >> m;
	init(n);
	
	fo(i, 0, m) {
		cin >> a >> b;
		union_sets(a, b);
	}
	
	int ans = 0;
	foe(i, 1, n)
	ans = max(ans, sz[find_parent(i)]);
	cout << ans;
}
