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

typedef pair<int, int> P;

int main()
{
    int n;
    cin >> n;

    map<P, int> mp;
    for (int i = 1; i <= n; i++) {
        int last = i % 10;  // 末尾
        int num = i;
        while (num >= 10) {
            num /= 10;
        }
        int first = num;  // 先頭
        mp[P(first, last)]++;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int last = i % 10;  // 末尾
        int num = i;
        while (num >= 10) {
            num /= 10;
        }
        int first = num;  // 先頭
        ans += mp[P(last, first)];
    }
    cout << ans << endl;
    return 0;
}