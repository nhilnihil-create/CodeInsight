#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <numeric>
#include <cmath>
#include <iomanip> //cout << fixed << setprecision(15) << << endl;
#include <cassert>
//#include "atcoder/all"

using namespace std;
//using namespace atcoder;

typedef long long ll;

#define pb push_back
#define rep(i, n) for(int i=0;i<(n);i++)
#define REP(i, n) for(int i=1;i<=(n);i++)
#define P pair<int,int>

int mx8[] = {0, 0, 1, -1, -1, 1, -1, 1};
int my8[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int mx4[] = {1, -1, 0, 0};
int my4[] = {0, 0, -1, 1};

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    unsigned long long ans = 1;
    vector<unsigned long long> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    rep(i, n)
    {
        if (a[i] == 0)
        {
            cout << 0 << endl;
            return 0;
        }
        if (ans > 1000000000000000000 / a[i])
        {
            cout << -1 << endl;
            return 0;
        }
        ans *= a[i];
    }
    cout << ans << endl;
}