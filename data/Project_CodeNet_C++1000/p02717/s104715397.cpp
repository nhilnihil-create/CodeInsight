#include <bits/stdc++.h>
#define boost ios_base::sync_with_stdio(0); cin.tie(); cout.tie()
#define all(x) x.begin(), x.end()
#define endl '\n'
#define len(a) a.length()
#define TIME cout << endl << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;

using namespace std;

const int inf = 1e9;
const double eps = 1e-1;
const int mod = 1e9 + 7;

typedef long long ll;

bool check_pow_2 (ll n) {return (n & (n - 1) == 0);}
bool is_prime (int a) { for (int i = 2; i <= sqrt(a); i++) if (a % i == 0) return false; return true; }
ll div_up (ll x, ll y) { if (x == 0) return 0; return (x - 1) / y + 1; }

int32_t main()
{
    boost;
    int a, b, c; cin >> a >> b >> c;
    cout << c << " " << a << " " << b;
    return 0;
}
/*
*/
