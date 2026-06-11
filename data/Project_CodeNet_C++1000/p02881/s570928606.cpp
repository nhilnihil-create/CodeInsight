#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    ll n; cin >> n;
    ll res = n - 1;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0) res = min(res, i-1 + n/i-1);
    }
    cout << res << endl;
    return 0;
}
