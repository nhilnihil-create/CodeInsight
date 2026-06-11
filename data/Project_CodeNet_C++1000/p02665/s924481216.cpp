#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define endl "\n"
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    int n;
    cin >> n;
    vector<ll> arr(n+1, 0);
    for(auto& val: arr)
        cin >> val;
    vector<ll> rem(n+1, 0);
    rem[0] = 1;
    
    for(int i = 0; i <= n; i++) {
        if (i > 0) rem[i] = rem[i-1]*2;
        rem[i] -= arr[i];
        if (rem[i] < 0) {
            cout << -1 << endl;
            return 0;
        } else if (rem[i] >= 1e14) {
            rem[i] = 1e14;
        }
    }
    ll ans = 0;
    for(int i = n; i >= 0; i--) {
        ll upper = rem[i] + arr[i];
        if (i < n)
            arr[i] += arr[i+1];
        arr[i] = min(arr[i], upper);
        // cout << "i = " << i << ", add " << arr[i] << endl;
        ans += arr[i];
    }
    cout << ans << endl;
    return 0;
}
