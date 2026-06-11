#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <utility> 
#include <tuple> 
#include <cstdint> 
#include <cstdio> 
#include <map> 
#include <queue> 
#include <set> 
#include <stack> 
#include <deque> 
#include <unordered_map> 
#include <unordered_set> 
#include <bitset> 
#include <cctype> 
#include <cmath>
#include <iomanip>
#include <ctype.h>

using namespace std;
using ll = long long;
using PAIR = pair<int, int>;
using PAIRLL = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;

#define TR ","
#define fi first
#define se second
#define rep(i,N) for(int i=0;i<(int)N;++i)
#define all(v) v.begin(), v.end()
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll x, ll y) {
    return x / gcd(x, y) * y;
}

ll waz = 76543217;

ll inv(ll x) {
    if (x == 1) { return 1; }
    if (x == 0) { return 0; }
    else {
        ll a = (waz - inv(waz % x) * (waz / x)) % waz;
        if (a >= 0) { return a; }
        else { return waz + a; }
    }
}

void printVector(const vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

vector<ll> p;

ll phi(ll x) {
    ll a = x;
    ll b = x;
    for (ll k = 0; k != p.size(); ++k) {
        if (a % p[k] == 0) {
            while (a % p[k] == 0) {
                a /= p[k];
            }
            b = b / p[k] * (p[k] - 1);
        }
        if (a == 1) { break; }
    }
    return b;
}

bool my_compare(pair<string, int> a, pair<string, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }

    if (a.second != b.second) {
        return a.second > b.second;
    }
    else {
        return true;
    }
}

int main()
{
    IO;

    int N; cin >> N;
    vi d(N);
    rep(i, N) cin >> d[i];

    sort(d.begin(), d.end());

    cout << d[N / 2] - d[N / 2 - 1] << endl;
}