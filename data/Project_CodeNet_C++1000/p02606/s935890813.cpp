#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, ll>
#define vi vector <int>
#define graph vector <vi>
#define tam 300010
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int l, r, d;
	cin >> l >> r >> d;
	int cont = 0;
	for (int i = 1; i * d <= r; i++) {
		if (i * d >= l) cont++;
	}
	cout << cont << "\n";
	return 0;
}