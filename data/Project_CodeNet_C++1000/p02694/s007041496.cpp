
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#include <vector>
#include <numeric>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <tuple>

using ll = long long int;
using ul = unsigned long long int;
const ll LL_MAX (1LL<<60);
const ll MOD (1000000007);

#define rep(i,s,e) for(ll i=(s); i<(e); i++) 

using namespace std;

using T = tuple<ll,ll>;
using Graph = vector<vector<T>>;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll x;
    cin >> x;

    ll s(100);
    for (ll i=0; ; i++)
    {
        if (s>=x)
        {
            cout << i << endl;
            return 0;
        }

        s += s / 100;
        //cout << gain << ' ' << s << endl;
    }

    return 0;
}
