#include <bits/stdc++.h>

#define fastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef long double ld;

vector<int> parent;

int find_parent(int n)
{
	if (n != parent[n]) 
		parent[n] = find_parent(parent[n]);
	return parent[n];
}

int main()
{
	fastIO;
	int N, M;
	cin >> N >> M;
	parent.resize(N + 1);
	for (int i = 1; i <= N; i++) 
		parent[i] = i;
	int A, B;
	while (M--)
	{
		cin >> A >> B;
		if (A > B) swap(A, B);
		int parent_A = find_parent(A), parent_B = find_parent(B);
		parent[parent_B] = parent_A;
	}
	set<int> unique_parents;
	for (int i = 1; i <= N; i++)
		unique_parents.insert(find_parent(i));
	cout << unique_parents.size() - 1;
}