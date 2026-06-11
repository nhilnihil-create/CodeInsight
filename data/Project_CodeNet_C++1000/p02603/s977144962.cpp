#include <bits/stdc++.h>
//#include "atcoder/all"
typedef long long int ll;
using namespace std;
// using namespace atcoder;
int main() {
    ll n;
    cin >> n;
    ll a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    bool uritai = false;
    ll now = 1;
    ll shojikin = 1000;
    ll shojikabu = 0;
    ll ret = 1000;
    while (now <= n) {
        if (uritai) {
            if ((now < n) && (a[now] < a[now + 1])) {
                now++;
                continue;
            }
            else {
                shojikin += shojikabu * a[now];
                shojikabu = 0;
                uritai = false;
                if (ret < shojikin) {
                    ret = shojikin;
                }
            }
        }
        else {
            //安く買いたい
            if ((now == n) || (a[now] > a[now + 1])) {
                now++;
                continue;
            }
            else {
                shojikabu = shojikin / a[now];
                shojikin %= a[now];
                uritai = true;
            }
        }
        now++;
    }
    cout << ret << endl;
    return 0;
}