#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#include <complex>
#include <unistd.h>
#include <cassert>
#include <cctype>
#include <random>
#include <time.h>
#define _USE_MATH_DEFINES
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef pair<double, ll> pdlg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef tuple<double, double, double> tddd;
typedef complex<double> xy_t;
typedef vector<ll> vll;
typedef vector< vector<ll> > matrix;
#define REP(i, x, y) for(ll i = (ll)x; i < (ll)y; i++)
#define DREP(i, x, y, d) for(ll i = (ll)x; i < (ll)y; i += (ll)d)
#define PER(i, x, y) for(ll i = (ll)x; i > (ll)y; i--)
#define DPER(i, x, y, d) for(ll i = (ll)x; i > (ll)y; i -= (ll)d)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
int iinf = intmax / 8;
ll inf = llmax / 8;
double eps = 1e-12;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll len = (1 << N);
    ll S[len];
    REP(i, 0, len) {
        cin >> S[i];
    }
    sort(S, S + len);
    reverse(S, S + len);
    ll smod[len];
    ll modnum = 0;
    smod[0] = 0;
    REP(i, 1, len) {
        if (S[i] != S[i - 1]) {
            modnum++;
        }
        smod[i] = modnum;
    }
    bool ok = true;
    if (smod[1] == 0) {
        ok = false;
    }
    ll gen[N];
    fill(gen, gen + N, 0);
    ll newgen[N];
    fill(newgen, newgen + N, 0);
    fill(gen, gen + N, 1);
    ll maxgen = N - 1;
    REP(i, 1, len) {
        if (smod[i] != smod[i - 1]) {
            REP(j, 0, N) {
                newgen[j] += gen[j];
                gen[j] = newgen[j];
                newgen[j] = 0;
            }
            maxgen = -1;
            PER(j, N - 1, -1) {
                if (gen[j] != 0) {
                    maxgen = j;
                    break;
                }
            }
        }
        if (maxgen == -1) {
            ok = false;
            break;
        }
        REP(j, 0, maxgen) {
            newgen[j]++;
        }
        gen[maxgen]--;
        if (gen[maxgen] == 0) {
            maxgen--;
        }
    }
    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
