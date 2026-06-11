#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<tuple>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int d[200005];
int main(void) {
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    int x = *max_element(d, d + n);
    sort(d, d + n);
    for (int i = 1; i <= x; i++) {
        int index = lower_bound(d, d + n, i)-d;
        if (index + 1 == n - index + 1) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

