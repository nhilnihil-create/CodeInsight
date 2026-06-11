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
    ll a, b, n;
    cin >> a >> b >> n;
    if (n >= b) cout << a * (b - 1) / b - a * ((b - 1) / b);
    else cout << a * n / b - a * (n / b);
}
