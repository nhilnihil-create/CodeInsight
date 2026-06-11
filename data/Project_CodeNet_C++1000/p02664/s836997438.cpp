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
    string t;
    cin >> t;
    string ans;
    rep(i, t.size()) {
        if (t[i] == 'P') {
            ans += 'P';
        }
        else if (t[i] == 'D') {
            ans += 'D';
        }
        else {
            ans += 'D';
        }
    }
    cout << ans << endl;
    return 0;
}