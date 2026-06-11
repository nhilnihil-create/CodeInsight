#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define INF 10e12
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int ans = 0;
    if (s == "SUN")
        ans = 7;
    if (s == "MON")
        ans = 6;
    if (s == "TUE")
        ans = 5;
    if (s == "WED")
        ans = 4;
    if (s == "THU")
        ans = 3;
    if (s == "FRI")
        ans = 2;
    if (s == "SAT")
        ans = 1;
    cout << ans << endl;
}