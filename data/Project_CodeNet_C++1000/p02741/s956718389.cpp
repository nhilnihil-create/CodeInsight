#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define fst first
#define sc second
#define snd second
#define sz(X) (int)(X).size()
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fornr(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forab(i, a, b) for(int i = int(a); i < int(b); i++)
#define all(X) X.begin(), X.end()

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ld;
typedef vector<int> vi;
typedef vector<pair<ll, ll>> vpll;

//mt19937 random(566);
//uniform_int_distribution<ll> distr;
//ll rnd(ll a, ll b) {return a + distr(random) % (b - a + 1);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vi a{1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    int k;
    cin >> k;
    k--;
    cout << a[k];
    return 0;
}