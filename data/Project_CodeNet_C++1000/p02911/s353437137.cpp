// https://atcoder.jp/contests/abc141/tasks/abc141_c
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
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(Q);
    REP(i, Q) cin >> A[i], --A[i];
    vector<int> cnts(N, 0);
    REP(i, Q)
    {
        ++cnts[A[i]];
    }
    vector<int> res(N, K);
    REP(i, N)
    {
        res[i] += cnts[i] - Q;
    }
    REP(i, N)
    {
        if (res[i] > 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
