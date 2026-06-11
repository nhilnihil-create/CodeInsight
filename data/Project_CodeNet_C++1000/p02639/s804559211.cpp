#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <cassert>
#include <unordered_map>

using namespace std;
const int MOD = 1000000007;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b,c,d,e; cin >> a >> b >> c >> d >> e;
    if (a == 0)
        cout << 1 << '\n';
    else if (b == 0)
        cout << 2 << '\n';
    else if (c == 0)
        cout << 3 << '\n';
    else if (d == 0)
        cout << 4 << '\n';
    else
        cout << 5 << '\n';
    return 0;
}

