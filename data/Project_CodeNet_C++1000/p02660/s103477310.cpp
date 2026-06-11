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

    ll n; cin >> n;
    ll ans = 0;
    ll N = n;
    for(ll i = 2; i*i<=n; ++i)
    {
        int k = 0;
        while(N%i==0)
        {
            N /= i;
            k++;
        }
        ans += floor((-1 + sqrt(1+8*k)) / 2);
    }
    if(N > 1) ans += 1;
    cout << ans << endl;
}