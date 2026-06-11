#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)     for (ll i = 0; i < (n); ++i)
#define rep2(i, a, b) for (ll i = (a); i < (b); ++i)
#define repin(a, n)  \
    vector<ll> a(n); \
    rep(i, n) { cin >> a[i]; }
#define repins(a, n)     \
    vector<string> a(n); \
    rep(i, n) { cin >> a[i]; }
#define repind(a, n)     \
    vector<double> a(n); \
    rep(i, n) { cin >> a[i]; }
#define in(a) \
    ll a;     \
    cin >> a;
#define ins(a) \
    string a;  \
    cin >> a;
#define ind(a) \
    double a;  \
    cin >> a;
template <class T>
inline void out(T a) {
    cout << a << endl;
}
inline void out(double a) { printf("%.10f\n", a); }
#define all(x)  (x).begin(), (x).end()    //昇順
#define rall(x) (x).rbegin(), (x).rend()  //降順
#define yes     out("Yes");
#define no      out("No");

int main() {
    in(n);
    in(d);
    ll ans = 0;
    rep(i, n) {
        in(x);
        in(y);
        if (d * d >= x * x + y * y) {
            ans++;
        }
    }
    out(ans);
}