#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, a;
    double z = 0;
    cin >> n;
    while (n--) cin >> a, z += 1.0 / a;
    cout << 1 / z;
}
