// https://atcoder.jp/contests/abc133/tasks/abc133_d
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
#define READD(n) scanf("%d", &n)
int main()
{
    int N;
    READD(N);
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    vector<ll> B(N, 0);
    int sig = 1;
    REP(i, N)
    {
        B[0] += sig * A[i];
        sig *= -1;
    }
    for (int i = 1; i < N; ++i)
    {
        B[i] = 2 * A[i - 1] - B[i - 1];
    }
    REP(i, N)
    {
        printf("%lld", B[i]);
        if (i == N - 1) printf("\n");
        else printf(" ");
    }
    return 0;
}
