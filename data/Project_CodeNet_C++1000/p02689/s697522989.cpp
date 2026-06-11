#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i=0; i<n; i++)
 
using namespace std;
const double PI = acos(-1);
using Graph = vector<vector<int>>;
 
int main() {
	int n, m;
	cin >> n >> m;
	vector<ll> h(n+1);
	vector<ll> highest(n+1, 1);
	for (int i = 1; i < n+1; i++)
	{
		cin >> h[i];
	}
	rep(i, m)
	{
		int a, b;
		cin >> a >> b;
		if (h[a] <= h[b])
			highest[a] = 0;
		if (h[b] <= h[a])
			highest[b] = 0;
	}
	int count = 0;
	for (int i = 1; i < n+1; i++)
	{
		count += highest[i];
	}
	cout << count << endl;
}