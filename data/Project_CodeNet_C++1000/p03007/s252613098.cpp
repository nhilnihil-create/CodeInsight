#include "bits/stdc++.h"
#define ALL(obj) (obj).begin(),(obj).end()
#define RALL(obj) (obj).rbegin(),(obj).rend()
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = (int)(n); i >= 0; i--)
#define FOR(i,n,m) for(int i = (int)(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 4e18;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n) {
        cin >> a[i];
    }
    sort(ALL(a));
    if (a[0] < 0 && a[n-1] > 0) {
        vector<pair<ll, ll>> out;
        int k;
        for (k = n - 1; a[k-1] > 0; k--) {
            out.push_back({a[0],a[k]});
            a[0] = a[0] - a[k];
        }
        for (int i = 0; i < k; i++) {
            out.push_back({a[k],a[i]});
            a[k] = a[k] - a[i];
        }
        cout << a[k] << endl;
        for (auto p : out) {
            cout << p.first << " " << p.second << endl;
        }
    }
    else if (a[0] >= 0) {
        vector<pair<ll, ll>> out;
        for (int i = 1; i < n - 1; i++) {
            out.push_back({a[0],a[i]});
            a[0] -= a[i];
        }
        out.push_back({a[n-1],a[0]});
        a[n - 1] -= a[0];
        cout << a[n-1] << endl;
        for (auto p : out) {
            cout << p.first << " " << p.second << endl;
        }
    }
    else {
        vector<pair<ll, ll>> out;
        for (int i = 0; i < n - 1; i++) {
            out.push_back({a[n-1],a[i]});
            a[n-1] -= a[i];
        }
        cout << a[n - 1] << endl;
        for (auto p : out) {
            cout << p.first << " " << p.second << endl;
        }
    }
    getchar(); getchar();
}