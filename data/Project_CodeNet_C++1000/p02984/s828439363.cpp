#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;


int main() {
    int n; cin >> n;
    V<ll> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }

    ll tmp = 0;
    for(int i = 1; i < n; i+=2){
        tmp += 2 * a[i];
    }

    V<ll> ans(n);
    ans[0] = sum - tmp;
    for(int i = 1; i < n; i++){
        ans[i] = 2 * a[i - 1] - ans[i - 1];
    }

    for(int i = 0; i < n; i++){
        if(i != n - 1) cout << ans[i] << " ";
        else cout << ans[i] << endl;
    }
}
