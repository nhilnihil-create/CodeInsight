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
    vector<char> c(N);
    ll n_r = 0, n_w = 0;
    ll ans = 0;
    rep(0, i, N)
    {
        cin >> c.at(i);
        if (c.at(i) == 'R')
        {
            n_r++;
        }
        else
        {
            n_w++;
        }
    }
    rep(0, i, n_r)
    {
        if (c.at(i) == 'W')
        {
            ans++;
        }
    }
    cout << ans << endl;
}