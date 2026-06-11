#include<bits/stdc++.h>
#define ll long long
#define pr pair<ll,ll>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<pr > Q;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		Q.push_back({ a,i });
	}
	sort(Q.begin(), Q.end());
	for (pr p : Q) {
		cout << p.second+1<<' ';
	}
	return 0;
}