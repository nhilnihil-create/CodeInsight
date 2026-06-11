#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define vv(Type, n,m,d)vector<vector<Type>> vv(n, vector<Type>(m, d));

using namespace std;
using ll = long long;


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector <queue<string>> a(n+1);

	rep(i, m) {
		int b;
		string c;
		cin >> b >> c;
		a[b].push(c);
	}

	int aac = 0;
	int awa = 0;

	rep(i, n+1) {
		int wa = 0;
		while (!a[i].empty()) {
			string q = a[i].front();
			a[i].pop();
			if (q == "WA") wa++;
			if (q == "AC") {
				aac += 1;
				awa += wa;
				break;
			}
		}

	}

	cout << aac << " " << awa << endl;

	return 0;
}
