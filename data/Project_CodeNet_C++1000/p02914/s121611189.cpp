#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <map>
#include <queue>
#include <cstdio>
#include <complex>
#include <numeric>
#include <string.h>
#include <random>
#define rep(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
typedef pair<ll, ll> pl;
double PI = 3.141592653589793238462643383279;
const double EPS = 1e-9;
const ll MOD = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;

int n;
ll a[100001];
bool tmp[100001];
ll A = 0;
ll ans = 0;
map<int, vector<int>> v;

int main() {
    cin >> n;
    rep(i,n) cin >> a[i];
    /*
    rep(i,n) {
        cout << bitset<10>(a[i]) << endl;
    }
    */
    rep(i,n) A ^= a[i];
    for (ll i = 59; i >= 0; i--) {
        if (A&(1LL<<i)) {
            ans += (1LL<<i);
            continue;
        }
        /*
        if (i == 0) {
        cerr << "v" <<  " " << ans << endl;
        for (auto it = v.begin(); it != v.end(); it++) {
            cerr << (*it).first << endl;
            vector<int> &hoge = (*it).second;
            rep(i,hoge.size()) cerr << hoge[i] << " ";
            cerr << endl;
        }
        }
        */
        memset(tmp, 0, sizeof(tmp));
        int f = inf;
        rep(j,n) {
            if (!(a[j]&(1LL<<i))) continue;
            tmp[j] = true;
            f = min(f,j);
        }
        if (f == inf) continue;
        tmp[n] = true;
        for (auto it = v.begin(); it != v.end(); it++) {
            if (!tmp[(*it).first]) { continue; }
            if ((*it).first > f) {  continue; }
            vector<int> &tv = (*it).second;
            f = inf;
            rep(j,tv.size()) {
                tmp[tv[j]] ^= 1;
                if (tmp[tv[j]]) f = min(f,tv[j]);
            }
            /*
            if (i == 0) {
                cerr << f << endl;
                for (int _ = 0; _ <= n; _++) {
                    cerr << tmp[_];
                }
                cerr << endl;
            }
            */
        }
        vector<int> tv;
        f = inf;
        rep(j,n+1) {
            if (tmp[j]) {
                tv.push_back(j);
                f = min(f,j);
            }
        }
        if (tv.size() == 0) {
            ans += (1LL<<i)*2;
            continue;
        }
        if (f == n) {
            continue;
        }
        ans += (1LL<<i)*2;
        v[f] = tv;
    }
    cout << ans << endl;
}