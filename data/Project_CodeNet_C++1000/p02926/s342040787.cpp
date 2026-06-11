#include <bits/stdc++.h>
using namespace std;

//g++ -g -o yourexe yourfile.cpp
//./yourexe < yourinput.in > youroutput.out

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define M 1000000007

#define ll long long
#define ld long double
#define vi vector<ll>
#define pi pair<ll, ll>
#define vii vector<pi>
#define vvi vector<vi>
#define pb push_back
#define endl "\n"
#define fi first
#define se second

#define REP(i, s, e) for (ll i = s; i < e; i++)
#define RREP(i, s, e) for (ll i = s; i > e; i--)

#define all(v) v.begin(), v.end()
#define part(v, s, e) v.begin() + s, v.begin() + e
#define print(v) for (auto i: v) cout << i << " ";

struct point {
    ll x, y, q;
};

int main() {
    fast
    ll n;
    cin >> n;
    vector<point> pnt(n);
    REP(i, 0, n) {
        cin >> pnt[i].x >> pnt[i].y;
        if (pnt[i].x >= 0 && pnt[i].y >= 0)
            pnt[i].q = 1;
        else if (pnt[i].x < 0 && pnt[i].y >= 0)
            pnt[i].q = 2;
        else if (pnt[i].x < 0 && pnt[i].y < 0)
            pnt[i].q = 3;
        else
            pnt[i].q = 4;
    }
    sort(all(pnt), [](point a, point b) {
        if (a.q == b.q) {
            if (!a.x && !b.x)
                return a.y < b.y;
            ll g = __gcd(abs(a.x), abs(b.x)), u = LLONG_MAX, v = LLONG_MAX;
            if (a.q >= 3)
            	u = LLONG_MIN, v = LLONG_MIN;
            g = (a.x * b.x)/g;
            if (a.x)
                u = a.y * (g/a.x);
            if (b.x)
                v = b.y * (g/b.x);
            return u < v;
        }
        return a.q < b.q;
    });
    ll ans = 0, xs = 0, ys = 0, r;
    REP(i, 0, n) {
        xs = 0, ys = 0;
        r = i;
        REP(j, 0, n) {
            xs += pnt[r].x;
            ys += pnt[r].y;
            r = (r+1)%n;
            ans = max(ans, xs*xs + ys*ys);
        }
    }
    cout << fixed << setprecision(32) << sqrt((ld)ans) << endl;
    return 0;
}
