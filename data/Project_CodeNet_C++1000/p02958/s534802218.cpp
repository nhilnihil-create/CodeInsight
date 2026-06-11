#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int>v1(n + 1), v2(n + 1);
	for (int i = 0; i < n; i++)v1[i] = i + 1;
	for (int i = 0; i < n; i++) {
		cin >> v2[i];
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (v1[i] != v2[i])cnt++;
	}
	if (cnt > 2)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;




}