#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    if (k <= a) cout << k;
    else {
        k -= a;
        if (k <= b) cout << a;
        else {
            k -= b;
            cout << a - k;
        }
    }
}
