#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 1; i < n; i++)
typedef long long ll;
typedef pair<int, int> pii;


int main() {
    ll n; cin >> n;
    n--;
    ll ans = n * (n + 1) / 2;
    cout << ans << endl;
    return 0;
}
