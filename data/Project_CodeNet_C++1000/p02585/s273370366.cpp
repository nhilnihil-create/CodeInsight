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
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> p(N), c(N);

    rep(0, i, N)
    {
        cin >> p.at(i);
        p.at(i)--;
    }
    rep(0, i, N)
    {
        cin >> c.at(i);
    }

    ll ans = -1000000000000000;
    rep(0, i, N)
    {
        ll now = p.at(i);
        vector<ll> sub;
        while (now != i)
        {
            sub.push_back(c.at(now));
            now = p.at(now);
        }
        sub.push_back(c.at(now));

        if (sub.size() >= K)
        {
            ll sum = 0;
            rep(0, j, K)
            {
                sum += sub.at(j);
                ans = max(ans, sum);
            }
        }
        else
        {
            ll subsum = 0;
            rep(0, j, sub.size())
            {
                subsum += sub.at(j);
                ans = max(ans, subsum);
            }
            ll sum = subsum * (K / sub.size());
            if (K % sub.size() == 0)
            {
                sum -= subsum;
                rep(0, j, sub.size())
                {
                    sum += sub.at(j);
                    ans = max(ans, sum);
                }
            }
            else
            {
                rep(0, j, K - sub.size() * (K / sub.size()))
                {
                    sum += sub.at(j);
                    ans = max(ans, sum);
                }
            }
        }
    }

    cout << ans << endl;
}