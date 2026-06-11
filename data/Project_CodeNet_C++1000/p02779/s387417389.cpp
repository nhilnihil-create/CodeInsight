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
    int n, a;
    set<int> s;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a, s.insert(a);
    if (s.size() == n) cout << "YES";
    else cout << "NO";
}
