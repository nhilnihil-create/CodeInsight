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
    string s, t, u;
    int a, b;
    cin >> s >> t >> a >> b >> u;
    if (s == u) cout << a - 1 << ' ' << b;
    else cout << a << ' ' << b - 1;
}
