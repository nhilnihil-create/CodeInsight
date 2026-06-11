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
    int n, x[8] = {}, y[8] = {}, a[8] = {0, 1, 2, 3, 4, 5, 6, 7}, c = 0;
    double z = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    do {
        for (int j = 1; j < n; j++) z += hypot(x[a[j]] - x[a[j - 1]], y[a[j]] - y[a[j - 1]]);
        c++;
    } while (next_permutation(a, a + n));
    cout << setprecision(13) << z / c;
}
