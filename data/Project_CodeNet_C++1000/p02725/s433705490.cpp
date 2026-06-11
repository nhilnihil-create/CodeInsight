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
    int K, N;
    cin >> K >> N;
    vector<ll> A(N);
    REP(i, N)
    {
        cin >> A[i];
    }
    ll dmax = K - A[N - 1] + A[0];
    for (int i = 1; i < N; ++i)
    {
        ll d = A[i] - A[i - 1];
        dmax = max(dmax, d);
    }
    ll ans = K - dmax;
    cout << ans << endl;
    return 0;
}
