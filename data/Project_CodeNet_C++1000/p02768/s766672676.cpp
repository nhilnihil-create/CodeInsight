#include <bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define P 1000000007
#define in(x, a, b) (a <= x && x < b)

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
const ll inf = 1000000001, INF = (ll)1e18 + 1;

int power(ll a, ll b) {
	ll result = 1;
	while(b) {
		if(b % 2) result = (result * a) % P;
		a = (a * a) % P;
		b /= 2;
	} 
	
	return result;
}

int divide(ll a, ll b) {
	return (a * power(b, P - 2)) % P;
}

int C(int n, int k) {
	ll result = 1, inv = 1;
	for(int i = n - k + 1; i <= n; i++) result = (result * i) % P;
	for(int i = 1; i <= k; i++) inv = (inv * i) % P;
	result = divide(result, inv);
	
	return result;
}

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	
	cout << (((power(2, n) - C(n, a) + P) % P - C(n, b) + P) % P - 1) % P << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}