#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const int INF = 1000000000;
const double PI = acos(-1);
const ll mod = 1000000007;

int main()
{
    int n;
    string s, t;
    cin >> n >> s >> t;

    string ans;
    rep(i, n) {
        ans += s[i];
        ans += t[i];
    }
    cout << ans << endl;
    return 0;
}