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
    string s, t;
    cin >> n >> m;
    for (int i = 0; i < n; i++) s += (char)(m + '0');
    for (int i = 0; i < m; i++) t += (char)(n + '0');
    cout << min(s, t);
}
