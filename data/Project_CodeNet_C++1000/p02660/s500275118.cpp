#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <fstream>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;
typedef vector<iii> viii;
typedef priority_queue<int> pqi;
typedef priority_queue<ii> pqii;
typedef map<int, int> mii;
typedef map<int, string> mis;
typedef map<string, int> msi;
typedef set<int> si;
typedef set<ll> sl;
typedef map<ll, ll> mll;
typedef queue<int> qi;
typedef queue<ii> qii;
typedef queue<iii> qiii;
typedef vector<string> vs;
typedef pair<ll, ll> iil;
typedef vector<iil> viil;
typedef long double ld;
typedef vector<vi> vvi;

#define pb push_back
#define mp make_pair
#define rep(i, n) for (int i = 0 ; i < n ; i++)
#define MOD 1000000007
#define INF 1000000000

void solve() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 2 ; i * i <= n ; i++) {
        ll ct = 0;
        while (n % i == 0) {
            n /= i;
            ct++;
        }
        ll tri = 0;
        ll inc = 1;
        while (tri <= ct) {
            tri += inc;
            inc++;
        }
        inc--;
        if (ct > 0) {
        }
        ans += inc - 1;
    }
    if (n > 1) {
        ans++;
    }
    cout << ans << endl;
}

void querySolve() {
    int t;
    cin >> t;
    for (int i = 0 ; i < t ; i++) {
        solve();
    }
}

int main() {
    solve();
    //querySolve();
}
