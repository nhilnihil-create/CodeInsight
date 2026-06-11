// https://atcoder.jp/contests/abc152/tasks/abc152_c
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
    vector<int> P(N);
    REP(i, N) scanf("%d", &P[i]);
    int minp = P[0];
    int ans = 1;
    for (int i = 1; i < N; ++i)
    {
        minp = min(minp, P[i]);
        if (minp >= P[i]) ++ans;
    }
    cout << ans << endl;
    return 0;
}
