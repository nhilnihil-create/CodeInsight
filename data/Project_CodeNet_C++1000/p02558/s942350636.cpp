#include <bits/stdc++.h>
using namespace std;

#pragma warning( disable : 4996 )

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ss(s) scanf("%s", &s)
#define pi(n) printf("%d\n", n)
#define pll(n) printf("%lld\n", n)
#define ps(s) printf("%s\n", s)
#define FOR(i, a, b) for (int i=a;i<=b;i++)


typedef long long ll;

int find(int parent[], int i)
{
	if (parent[i] == -1)
		return i;
	return find(parent, parent[i]);
}


void Union(int parent[], int x, int y)
{
	int xset = find(parent, x);
	int yset = find(parent, y);
	if (xset != yset)
	{
		parent[xset] = yset;
	}
}

void solve() {
	int N, Q;
	cin >> N >> Q;
	
	int* parent = new int[N * sizeof(int)];

	memset(parent, -1, sizeof(int) * N);

	while (Q--) {
		int t, u, v;
		cin >> t >> u >> v;
		if (t) {
			if (find(parent, u) == find(parent, v)) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else {
			Union(parent, u, v);
		}
	}
}


int main() {
	solve();
}