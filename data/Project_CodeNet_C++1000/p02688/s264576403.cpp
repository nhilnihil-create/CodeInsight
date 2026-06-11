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
    int n, k, a[102] = {}, b, c, d = 0;
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> b;
        while (b--) cin >> c, a[c] = 1;
    }
    for (int i = 1; i <= n; i++) if (!a[i]) d++;
    cout << d;
}
