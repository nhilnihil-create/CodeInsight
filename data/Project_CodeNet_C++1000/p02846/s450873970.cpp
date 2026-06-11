#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cstring>
#include <queue>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cstdlib>

using namespace std;

//#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))

typedef long long ll;
typedef pair<ll, ll> P;

//const int MAX = 700000;
static const ll MOD = 1000000007;
//static const ll INF = 100000000;

int main() {
    ll T1, T2, A1, A2, B1, B2, ans = 0;

    // input
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;

    // process
    ll A_distance = T1 * A1 + T2 * A2;
    ll B_distance = T1 * B1 + T2 * B2;

    if (A_distance == B_distance) {
        cout << "infinity" << endl;
        return 0;
    }

    if ((A1 > B1 && A2 > B2) || (A1 < B1 && A2 < B2)) {
        cout << 0 << endl;
        return 0;
    }

    if (A_distance > B_distance) {
        if (A1 > B1) {
            cout << 0 << endl;
            return 0;
        } else {
            ll dis1 = A_distance - B_distance;
            ll dis2 = (B1 - A1) * T1;
            ans = dis2 / dis1 * 2;
            ll T = dis2 % dis1;
            if (T != 0) {
                ans++;
            }
        }
    } else {
        if (B1 > A1) {
            cout << 0 << endl;
            return 0;
        } else {
            ll dis1 = B_distance - A_distance;
            ll dis2 = (A1 - B1) * T1;
            ans = dis2 / dis1 * 2;
            ll T = dis2 % dis1;
            if (T != 0) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}