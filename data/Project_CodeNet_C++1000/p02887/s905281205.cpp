#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s += "0";
    int ans = 0;
    rep(i, n) {
        if (s[i] != s[i+1]) ++ans;
    }
    cout << ans << endl;
    return 0;
}
