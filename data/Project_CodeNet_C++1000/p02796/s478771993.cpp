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
typedef pair<int, int> Pint;
typedef pair<ll, ll> Pll;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    ll N;
    cin >> N;
    vector<Pll> T(N);
    ll x, l;
    rep(0, i, N)
    {
        cin >> x >> l;
        T.at(i).first = x + l;
        T.at(i).second = x - l;
    }
    sort(all(T));
    int ans = 0;
    ll left = -1000000000;
    rep(0, i, N)
    {
        if (T.at(i).second < left)
        {
            continue;
        }
        else
        {
            left = T.at(i).first;
            ans++;
        }
    }
    cout << ans << endl;
}