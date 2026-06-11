#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define ff first
#define ss second
#define pb push_back
#define int long long
#define ios std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define fill(x, v) memset(x, v, sizeof(x))
const ll mod = 1000000007;
const double pi = 3.14159265359; // PI
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
/*
std::cout << std::setprecision(9) << f << '\n';//3.141590000;
map<char,int>::reverse_iterator rit;
for(rit = mp.rbegin(); rit!=mp.rend(); rit++)
    auto start = high_resolution_clock::now();
    // Call the function, here
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by function: "<< duration.count() << " milliseconds" << endl;
*/
int power(int x, unsigned int y, int p)
{
    int res = 1;

    x = x % p;

    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
// string parser
vector<int> parse(string s)
{
    stringstream ss(s);
    int x;
    vector<int> v;
    while (ss >> x)
    {
        v.pb(x);
    }
    return v;
}
//-----------------------------
const int N = 1e7 + 9;
int mood = 998244353;
int n;

int32_t main()
{
    ios;
    int a, v, b, w, t;
    cin >> a >> v >> b >> w >> t;
    if (v * t >= abs(a - b) + w * t)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}