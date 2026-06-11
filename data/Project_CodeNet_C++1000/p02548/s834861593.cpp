#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned ll
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
const int N = 1e5 + 10;

int main() {
    ll n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += n / i;
        if (n % i == 0)
            ans--;
    }
    cout << ans << endl;
}