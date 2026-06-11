#include <bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define P 1000000007

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0);

	ll x;
	cin >> x;
	for(ll a = -1001; a < 1001; a++) {
		for(ll b = -1001; b < 1001; b++) {
			if(pow(a, 5) - pow(b, 5) == x) {
				cout << a << " " << b << endl;
				return 0;
			}
		}
	}
}