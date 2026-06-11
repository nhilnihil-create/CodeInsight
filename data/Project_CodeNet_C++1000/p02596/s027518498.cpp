#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iomanip>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;

int main() {
    ll k;
    cin >> k;
    ll a = 7;
    for (int i = 0; i <= k; i++) {
        if (a % k == 0) {
            cout << i+1 << endl;
            return 0;
        }
        a = (a*10+7)%k;
    }

    cout << -1 << endl;
    return 0;
}