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
    int n, z = 0;
    string s;
    map<string, int> m;
    cin >> n;
    while (n--) cin >> s, m[s]++;
    for (auto i : m) z = max(z, i.second);
    for (auto i : m) if (i.second == z) cout << i.first << '\n';
}
