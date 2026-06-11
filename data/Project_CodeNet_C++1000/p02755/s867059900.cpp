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
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= 1000000; i++) {
        int c = (int)(floor(i * 0.08) + 1e-9);
        int d = (int)(floor(i * 0.1) + 1e-9);
        if (c == a && d == b) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}
