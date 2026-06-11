#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define deb(x) cout << #x << " " << x << endl;
#define debarr(x) for (auto i : x) cout << i << " "; cout << endl;
#define debtwo(x,y) cout << #x << " " << x << ", " << #y << " " << y << endl;
#define mod 1000000007

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	if (s.back() == 's') {
		cout << s << "es" << endl;
	}
	else {
		cout << s << "s" << endl;
	}


}