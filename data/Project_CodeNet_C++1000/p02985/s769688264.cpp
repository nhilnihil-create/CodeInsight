#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
    int N; LLONG K; cin >> N >> K;
    vector<vector<int>> adList(N);
    for (int i = 0; i < N - 1; ++i)
    {
        int a, b; cin >> a >> b; --a; --b;
        adList[a].push_back(b);
        adList[b].push_back(a);
    }
    vector<bool> notColored(N, true);
    LLONG ans = K;
    notColored[0] = false;
    deque<int> Q;
    for (LLONG i = 0, n = adList[0].size(); i < n; ++i)
    {
        notColored[adList[0][i]] = false;
        Q.push_back(adList[0][i]);
        ans *= K - 1 - i;
        ans %= MOD;
    }
    while (!Q.empty())
    {
        int v = Q.front(); Q.pop_front();
        LLONG num = 0;
        for (const int n : adList[v])
        {
            if (notColored[n])
            {
                notColored[n] = false;
                Q.push_back(n);
                ++num;
            }
        }
        for (LLONG i = 0; i < num; ++i)
        {
            ans *= K - 2 - i;
            ans %= MOD;
        }
    }
    cout << ans << endl;
}
