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
    int n, m;
    cin >> n >> m;
    if (n % 2) {
        for (int i = 1; i <= m; i++) cout << i << ' ' << n - i << '\n';
    } else {
        for (int i = 1; i <= (m + 1) / 2; i++) cout << i << ' ' << n - i + 1 << '\n';
        for (int i = (m + 1) / 2 + 1; i <= m; i++) cout << i << ' ' << n - i << '\n';
    }
}
