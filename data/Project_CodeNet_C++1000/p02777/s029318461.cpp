#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sz(v) (int)((v).size())
#define pb push_back

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string r, b; cin >> r >> b;
	int nr, nb; cin >> nr >> nb;
	string u; cin >> u;
	if (u==r) nr--;
	else nb--;
	cout << nr << " " << nb << "\n";
}
