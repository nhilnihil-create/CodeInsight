#include <bits/stdc++.h>

using namespace std;

template<class T, class U>
void ckmin(T &a, U b)
{
    if (a > b) a = b;
}

template<class T, class U>
void ckmax(T &a, U b)
{
    if (a < b) a = b;
}

#define MP make_pair
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORD(i, a, b) for (auto i = (a) - 1; i >= (b); i--)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

const int MAXN = 1000013;

int N;
int arr[MAXN];
int twos[MAXN];
int ans;

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    string str; cin >> str;
    bool even = true;
    FOR(i, 0, N)
    {
        arr[i] = (str[i] - '1');
        if (arr[i] == 1)
        {
            even = false;
        }
    }
    twos[0] = 0;
    FOR(i, 1, N + 1)
    {
        twos[i] = twos[i - 1] + __builtin_ctz(i);
        // cerr << "tows " << i << " = " << twos[i] << endl;
    }
    if (even)
    {
        FOR(i, 0, N)
        {
            arr[i] >>= 1;
        }
    }
    //2022
    //220
    //02
    //2
    FOR(i, 0, N)
    {
        if (twos[N - 1] - twos[i] - twos[N - 1 - i] == 0 && arr[i] == 1)
        {
            ans ^= 1;
        }
    }
    //find it mod 2.
    if (even)
    {
        ans <<= 1;
    }
    cout << ans << '\n';
    return 0;
    //we need N choose everything mod 2.
    //if everything is even, solve and then divide by 2.
}
