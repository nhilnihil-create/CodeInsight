#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>
#define PI 3.141592653589793
const int INF = 1001001001;

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	if (c - a - b > 0) {
		if((c - a - b)*(c - a - b)>4 * a * b) cout << "Yes" << endl;
      else cout << "No" << endl;
	}
	else {
		cout << "No" << endl;
	}
}