#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, int> pdi;

const ll INF = 2e18;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll n, a, b;
	cin >> n >> a >> b;
	if(a > b) swap(a, b);
	if((b-a)%2) cout << min(a + (b-a-1)/2, n-b+1 + (n-(a+n-b+1))/2);
	else cout << (b-a)/2;
}
