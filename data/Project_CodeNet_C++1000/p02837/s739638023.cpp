// https://atcoder.jp/contests/abc147/tasks/abc147_c
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

int main()
{
    int N;
    scanf("%d", &N);
    vector<int> A(N);
    vector<vector<int>> x(N), y(N);
    REP(i, N)
    {
        scanf("%d", &A[i]);
        if (0 == A[i]) continue;
        x[i].resize(A[i]), y[i].resize(A[i]);
        REP(j, A[i])
        {
            scanf("%d %d", &x[i][j], &y[i][j]);
            --x[i][j];
        }
    }
    int ans = 0;
    vector<int> res(N, 0); // 1 : 正直者, 0:不親切
    ll blim = 1LL << N;
    // i + 1 桁目のビットが立っている場合 i 番目の人が正直者であるとして、bit全探索を行う
    for (ll b = 0; b < blim; ++b)
    {
        // b に基づいて res に値を格納する
        REP(i, N)
        {
            int bflag  = (b >> i) & 1;
            if (bflag == 0) res[i] = 0;
            else
            {
                res[i] = 1;
            }
        }

        // 正直者と仮定した人(res[i] == 1)の証言をチェック
        bool ok = true;
        REP(i, N)
        {
            if (res[i] == 0) continue;
            REP(j, A[i])
            {
                if (res[x[i][j]] != y[i][j])
                {
                    ok = false;
                    break;
                }
            }
        }
        if (ok)
        {
            int cnt = 0;
            REP(i, N)
            {
                if (res[i] == 1)
                    ++cnt;
            }
            ans = max(ans, cnt);
        }
    }
    printf("%d\n", ans);
    return 0;
}
