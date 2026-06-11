#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const int INF = 1000000000;
const double PI = 3.1415926535897932;
const ll MOD = 1000000007;

int main()
{
    ll n, k;
    string s;
    cin >> n >> k >> s;

    ll cnt = 0;
    rep(i, s.size()-1) {
        if (s[i] != s[i + 1]) cnt++;
    }
    cnt = max(ll(0), cnt - 2 * k);
    ll ans = n - 1 - cnt;
    cout << ans << endl;
    return 0;
}