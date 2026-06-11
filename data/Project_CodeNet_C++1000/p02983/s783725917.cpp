#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

/*
左から見ていったときの最大値と右から見ていったときの最大値を比較する

*/
int main()
{
    ll L, R;
    cin >> L >> R;
    ll ans = 2019;
    ll modL = L % 2019;
    ll modR = R % 2019;
    if (R - L >= 2018) {
        ans = 0;
    } else if (modL >= modR) {
        ans = 0;
    } else {
        for (ll i = L; i <= R; i++) {
            for (ll j = i + 1; j <= R; j++) {
                ll modi = i % 2019;
                ll modj = j % 2019;
                ans = min(ans, (modi * modj) % 2019);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
/*

最小値は非負

2050 4040
31 - 2018, 0, 1, 2

0 1 ... 2017

1 .... 2019
- j-i>=2018 -> 0
- j-i<2018
modi >= modj -> 0
    32 ..... 0 1

- j-i<2018 && modi < modj:
     32, 33, ...., 2016
     2000 の中で探して一番小さくなるものを選ぶ
31 - 51


*/