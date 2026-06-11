// https://atcoder.jp/contests/abc131/tasks/abc131_c
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)

template <class T>
T calcgcd(T x, T y)
{
    if (x < y)
    {
        std::swap(x, y); //小さい方をyとする
    }
    T r = x % y;
    while( r != 0 )
    {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}

int main()
{
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    ll ans = B - A + 1;
    ll E = C * D / calcgcd(C, D);
    ll cnt = B / C + B / D - B / E - A / C - A / D + A / E;
    if (A % C == 0 || A % D == 0) ++cnt;
    ans -= cnt;
    cout << ans << endl;
    return 0;
}
