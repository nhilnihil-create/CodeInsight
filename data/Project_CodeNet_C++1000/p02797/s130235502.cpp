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
typedef pair<int, int> Pint;
typedef pair<ll, ll> Pll;
#define rep(begin, i, end) for (ll i = begin; i < (ll)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    ll N, K, S;
    cin >> N >> K >> S;
    rep(0, i, K)
    {
        cout << S << ' ';
    }
    rep(0, i, N - K)
    {
        if (S == 1000000000)
        {
            cout << 1 << ' ';
        }
        else
        {
            cout << S + 1 << ' ';
        }
    }
    cout << endl;
}