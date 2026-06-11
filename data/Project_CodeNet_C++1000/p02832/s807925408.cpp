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
    int n, a, b = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a == b) b++;
    }
    if (b == 1) cout << -1;
    else cout << n - b + 1;
}
