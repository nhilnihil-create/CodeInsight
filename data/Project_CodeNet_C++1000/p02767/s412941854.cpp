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
    int n, a[102] = {}, z = mod;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < 128; i++) {
        int b = 0;
        for (int j = 0; j < n; j++) b += (a[j] - i) * (a[j] - i);
        z = min(z, b);
    }
    cout << z;
}
