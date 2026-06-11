// https://atcoder.jp/contests/abc174/tasks/abc174_e
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)
ll mod = 1000000000;
int main()
{
    ll S;
    cin >> S;
    ll x = (mod - S % mod)% mod;
    ll y = (S + x) / mod;
    cout << "0 0 1000000000 1 " << x << " " << y << endl;
    return 0;
}
