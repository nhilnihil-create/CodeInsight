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

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    ll amx = -1;
    REP(i, N)
    {
        cin >> A[i];
        amx = max(amx, A[i]);
    }
    if (0 == K)
    {
        cout << amx << endl;
        return 0;
    }
    ll left = 0, right = amx;
    while (right - left > 1)
    {
        ll mid = (left + right) / 2;
        ll cnt = 0;
        REP(i, N)
        {
            cnt += (A[i] + mid - 1) / mid - 1;
            if (cnt > K) break;
        }

        if (cnt <= K) right = mid;
        else left = mid;

    }

    cout << right << endl;
    return 0;
}
