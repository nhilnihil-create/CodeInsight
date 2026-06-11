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
    int n;
    ll a[200005] = {}, c[200005] = {}, z = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], c[a[i]]++;
    for (int i = 1; i <= n; i++) z += c[i] * (c[i] - 1) / 2;
    for (int i = 1; i <= n; i++) cout << z - c[a[i]] + 1 << '\n';
}
