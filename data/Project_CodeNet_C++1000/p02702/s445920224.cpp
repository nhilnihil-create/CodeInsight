#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef pair<int, int> ii;
typedef pair<i64, i64> ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

#define fastIO() ios_base::sync_with_stdio(0), cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ms(a, x) memset(a, x, sizeof(a))
#define len(x) (x).size()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

const double eps = 1e-9;
const double pi = acos(-1.0);
const int inf = 1e9;
const int maxn = 3e3+5;
const int mod = 2019;

string s;
int cur, ans, x, base, n;
int f[maxn], pot[200005];

int main() {
    fastIO();
    cin >> s;
    n = len(s);

    pot[n-1] = 1;
    for (int i = n-2; i >= 0; --i) pot[i] = (pot[i+1] * 10) % mod;

    f[0] = 1;
    for (int i = 0; i < n; ++i) {
    	cur = (cur + pot[i] * (s[i]-'0')) % mod;
    	ans += f[cur];
    	++f[cur];
    }

    cout << ans << '\n';
    return 0;
}
