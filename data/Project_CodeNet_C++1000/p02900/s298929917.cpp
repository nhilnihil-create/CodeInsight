#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

ll gcd(ll n, ll m) {
    if(n < m) swap(n, m);
    if(n % m == 0) return m;
    return gcd(m, n % m);
}

int main() {
    ll A, B; cin >> A >> B;
    ll G = gcd(A, B);
    ll ans = 1;
    for(ll i = 2; i * i <= G; i++) {
        if(G % i != 0) continue;
        ans++;
        while(G % i == 0) {
            G /= i;
        }
    }
    if(G != 1) ans++;
    cout << ans << endl;
    return 0;
}