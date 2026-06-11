// 
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
    string S, T;
    cin >> S >> T;
    int N = S.size();
    int m = T.size();
    int ans = m;
    for (int i = 0; i < N - m + 1; ++i)
    {
        int cnt = 0;
        for (int j = 0; j < m; ++j)
        {
            if (S[i + j] != T[j]) ++cnt;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
