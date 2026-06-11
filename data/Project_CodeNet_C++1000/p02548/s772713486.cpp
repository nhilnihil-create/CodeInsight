#include <iostream>
#include <fstream> 
#include <iomanip>
#include <cstdio> 
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <deque>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
const LL INF = (1LL << 60) - 1;
const LL MOD = 1e9 + 7;
const LL N = 200005;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    int n;
    cin >> n;
    LL ans = 0;
    for (int i = 1; i < n; i++) {
        ans = ans + (n - 1) / i;
    }
    cout << ans << endl;
}