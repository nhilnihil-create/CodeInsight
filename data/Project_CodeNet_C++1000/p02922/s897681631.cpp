#include <bits/stdc++.h>
using namespace std;
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef set<ii> sii;
typedef set<int> si;
typedef priority_queue<int> pqi;
typedef priority_queue<ii> pqii;

const int INF = 1000000010;
const ll MOD = 1000000007;

int main() {FIN
    
	int m, n, c, d = 0;
	cin >> m >> n;
	if (n > 1) {
		c = m; d = 1;
		while (c < n) {
			c += (m-1);
			d++;
		}
	}
	cout << d << "\n";
	
    return 0;
}
