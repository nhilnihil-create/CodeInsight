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

void dfs(char now, int n, string s) {
    if (int(s.size()) == n) {
        cout << s << endl;
        return;
    }
    for (char c = 'a'; c <= now+1; ++c) {
        dfs(((c>now)?(char(now+1)):now), n, s+c);
    }
    return;
}

int main() {
    int n;
    cin >> n;
    dfs('a', n, "a");
    return 0;
}
