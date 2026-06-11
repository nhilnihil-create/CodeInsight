#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, q;
	cin >> n >> k >> q;
	vector<int> a(n, k - q);
	for(int i = 0; i < q; i++) {
		int foo;
		cin >> foo;
		foo--;
		a[foo]++;
	}
	for(int i = 0; i < n; i++) {
		cout << (a[i] > 0 ? "Yes" : "No") << endl;
	}
}