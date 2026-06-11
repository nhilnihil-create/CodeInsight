#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;
const int mod = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        ll a = n / i;
        res += a * (a+1) / 2 * i;
    }
    cout << res << endl;
}