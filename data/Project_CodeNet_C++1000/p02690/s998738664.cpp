#include <algorithm>
#include <climits>
#include <complex>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <tuple>
#include <type_traits>
#include <vector>

#include <stdio.h>

using ll = long long;
using namespace std;

ll to5(ll a) { return a * a * a * a * a; }

int main() {
    ios::sync_with_stdio(false);
    ll x;
    cin >> x;

    for (int i = -120; i < 120; i++) {
        for (int j = -120; j < 120; j++) {
            if (to5(i) - to5(j) == x) {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
