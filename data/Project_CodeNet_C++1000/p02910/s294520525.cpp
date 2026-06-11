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
    string s;
    cin >> s;

    bool is_ok = true;
    rep(i, s.size()) {
        if (i % 2 == 0 && s[i] == 'L') is_ok = false;
        if (i % 2 != 0 && s[i] == 'R') is_ok = false;
    }
    if (is_ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}