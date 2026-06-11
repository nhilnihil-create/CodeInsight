#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <iomanip>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstdio>
#include <random>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <string.h>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(0, i, N)
    {
        cin >> A.at(i);
    }
    ll a = 0, b = 0;
    rep(0, i, N)
    {
        rep(0, j, N)
        {
            if (A.at(j) > A.at(i))
            {
                a++;
            }
        }
        rep(i + 1, j, N)
        {
            if (A.at(i) > A.at(j))
            {
                b++;
            }
        }
    }
    ll ans = ((a * ((K * (K - 1) / 2) % MOD) + b * K)) % MOD;
    cout << ans << endl;
}