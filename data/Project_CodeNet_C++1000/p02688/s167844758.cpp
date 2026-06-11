#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i=0; i<n; i++)
 
using namespace std;
const double PI = acos(-1);
using Graph = vector<vector<int>>;
 
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n+1, -1);
	rep(i, k)
	{
		int d;
		cin >> d;
		rep(j, d)
		{
			int index;
			cin >> index;
			a[index]++;
		}
	}
	int count = 0;
	for (int i = 1; i < n+1; i++)
	{
		if (a[i] == -1)
			count++;
	}
	cout << count << endl;
}