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
#include <random>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 10000000000;
const double PI = acos(-1);
const ll mod = 1000000007;

int n;
void dfs(string s, char max_c) {
    if (s.size() == n) {
        cout << s << endl;
        return;
    }
    for (char c = 'a'; c <= max_c + 1; c++) {
        string t = s;
        t += c;
        dfs(t, max(max_c, c));
    }
}

int main()
{
    cin >> n;
    dfs("", 'a'-1);
    return 0;
}
