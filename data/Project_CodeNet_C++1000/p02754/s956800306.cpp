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
    ll n, a, b;
    cin >> n >> a >> b;
    if (n % (a + b) < a) {
        cout << n / (a + b) * a + n % (a + b);
    } else {
        cout << n / (a + b) * a + a;
    }
}
