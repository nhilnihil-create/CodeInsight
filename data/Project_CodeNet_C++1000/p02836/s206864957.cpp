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
const ll INF = 1000000000000000000;
const double PI = acos(-1);

int main()
{
    string s;
    cin >> s;
    int ans = 0;
    rep(i, s.size() / 2) {
        if (s[i] != s[s.size() - 1 - i]) ans++;
    }
    cout << ans << endl;
    return 0;
}