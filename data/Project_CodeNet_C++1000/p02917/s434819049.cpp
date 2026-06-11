// https://atcoder.jp/contests/abc140/tasks/abc140_c
// 番兵(sentinel)を置くことでループの端を気にせずに処理する
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
#define SENTINEL 1000000;
int main()
{
    int N;
    cin >> N;
    vector<int> B(N + 1);
    B[0] = B[N] = SENTINEL;
    for (int i = 1; i < N; ++i) cin >> B[i];
    int ans = 0;
    REP(i, N)
    {
        ans += min(B[i], B[i + 1]);
    }
    cout << ans << endl;
    return 0;
}
