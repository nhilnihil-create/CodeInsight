#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<numeric>
#include<math.h>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    rep(i, n) {
        ll tmp_a;
        cin >> tmp_a;
        sum += tmp_a;
        if ( i == 0 ) a[i] = tmp_a;
        else          a[i] = tmp_a + a[i-1];
    }
    ll min_num = 1e18;
    rep(i, n) min_num = min(min_num, abs(sum - a[i] - a[i]));
    cout << min_num << endl;
    return 0;
}
