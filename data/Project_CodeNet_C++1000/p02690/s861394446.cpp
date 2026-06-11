#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    //a^5-b^5=(a-b)(a^4+a^3b+a^2b^2+ab^3+b^4)
    ll x;
    cin >> x;
    for (ll i = -1000; i <= 1000; i++) {
        for (ll j = -1000; j <= 1000; j++) {
            if (i * i * i * i * i - j * j * j * j * j == x) {
                cout << i << ' ' << j;
                return 0;
            }
        }
    }
}
