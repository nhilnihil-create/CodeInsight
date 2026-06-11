#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mk make_pair
#define all(a) a.begin(), a.end()
#define len(a) (int)a.size()

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

ll mod = 1e9 + 7;

int main(){
	int n;
	cin >> n;

	ll ten = 1, nine = 1, eight = 1;
	for(int i = 0; i < n; i++){
		ten = (ten * 10) % mod;
		nine = (nine * 9) % mod;
		eight = (eight * 8) % mod;
	}
	
	ll ans = ten - nine - nine + eight;
	ans %= mod;
	ans = (ans + mod) % mod;

	cout << ans << endl;
	return 0;
}
