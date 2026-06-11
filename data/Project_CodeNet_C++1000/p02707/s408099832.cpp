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

int main()
{
    int n;
    cin >> n;
    vector<int> ans(n, 0);
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        ans[a - 1]++;
    }

    rep(i, n) {
        cout << ans[i] << endl;
    }
    return 0;
}
