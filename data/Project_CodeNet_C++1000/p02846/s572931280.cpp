#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

int main() {
    ll t1, t2;
    ll a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    ll dis1 = t1 * (a1 - b1);
    ll dis2 = t1 * (a1 - b1) + t2 * (a2 - b2);

    if (dis2 == 0) {
        cout << "infinity" << endl;
        return 0;
    }
    ll s1 = dis1 / llabs(dis1);
    ll s2 = dis2 / llabs(dis2);
    if (s1 * s2 > 0)
        cout << "0" << endl;
    else if (s1 * s2 < 0) {
        if (llabs(dis2) > llabs(dis1)) {
            cout << 1 << endl;
            return 0;
        }
        // cout << llabs(dis1) << endl << llabs(dis2) << endl;
        if (llabs(dis1) % llabs(dis2) == 0) {
            cout << (llabs(dis1)/llabs(dis2))*2 << endl;
        } else {
            cout << (llabs(dis1)/llabs(dis2))*2+1 << endl;
        }

    }
    return 0;
}


