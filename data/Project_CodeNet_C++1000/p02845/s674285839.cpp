#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    ll N;
    cin >> N;
    vector<ll> a(100010);
    rep(0, i, N)
    {
        cin >> a.at(i);
    }

    vector<ll> num(100010, 0), T(100010, 0);
    map<ll, ll> m;
    ll ans = 1;
    T.at(0) = 3;
    rep(0, i, N)
    {
        if (i != 0)
        {
            rep(0, j, 3)
            {
                if (a.at(i) == num.at(j))
                {
                    T.at(i)++;
                }
            }
        }
        num.at(m[a.at(i)])++;
        m[a.at(i)]++;
        if (a.at(i) != 0 && m[a.at(i) - 1] == 0)
        {
            T.at(i) = 0;
        }
        ans *= T.at(i);
        ans %= MOD;
    }

    cout << ans << endl;
}
