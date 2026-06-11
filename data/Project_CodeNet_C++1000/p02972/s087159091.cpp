// https://atcoder.jp/contests/abc134/tasks/abc134_d
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
    cin >> N;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; ++i) cin >> a[i];
    int M = 0;
    vector<int> b(N + 1, 0);
    for (int i = N; i >= 1; --i)
    {
        int sum = 0;
        for (int k = i + i; k <= N; k += i)
        {
            if (k <= N && 1 == b[k])
            {
                sum += 1;
            }
        }
        if ((1 + sum) % 2 == a[i])
        {
            b[i] = 1;
            ++M;
        }
        else
        {
            b[i] = 0;
        }
        
    }
    printf("%d\n", M);
    for (int i = 1; i <= N; ++i)
    {
        if (b[i] == 1)
        {
            printf("%d", i);
            if (i != N) printf(" ");
        }
    }
    printf("\n");
    return 0;
}
