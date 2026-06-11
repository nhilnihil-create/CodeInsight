#include <bits/stdc++.h>
#define pb push_back
#define pll pair <ll, ll>
#define mp make_pair
#define pyshnapyshnakaa ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define x first
#define y second
#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
#define plll pair <ll, pair <ll, ll>>
#define pllll pair <pair <ll, ll>, pair <ll, ll> >
#define psl pair <string, ll>
#define all(a) a.begin(), a.end()
#define vvl vector <vector <ll> >
 
typedef long long ll;
 
typedef long double ld;
 
using namespace std;
 
const ll maxn = 1e6 + 100;
const ll maxc = 1e9;

ll n, m, k, t;

int main() {
    pyshnapyshnakaa;
    ll q, w, e, a, b, c;
    ll n;
    cin >> n;
    ll L = 0, R = maxc, M;
    while (R - L > 1) {
        M = (L + R) / 2;
        ll x = M * M - n;
        if (x >= 0) {
            R = M;
        }
        else {
            L = M;
        }
    }
    // assert(R <= maxc);
    a = -1, b = -1;
    while (a == -1) {
        ll x = R * R - n;
        // cout << "X " << x << endl;
        if (x == 0) {
            a = b = 0;
        }
        else {
            for (q = 1; q <= x; q++) {
                if (x % q == 0 && q <= R && x / q <= R) {
                    a = q;
                    b = x / q;
                    break;
                }
            }
        }
        if (a == -1) {
            R++;
        }
    }
    cout << R << " " << R << " ";
    // assert(a != -1);
    // if (a == -1) {
    //     cout << "SOSAT" << endl;
    //     exit(0);
    // }
    cout << 0 << " " << R - a << " ";
    cout << R - b << " " << 0;
    return 0;
}
