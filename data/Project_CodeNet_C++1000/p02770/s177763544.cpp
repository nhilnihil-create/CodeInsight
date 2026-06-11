#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pi pair<int, int>
#define pl pair<ll, ll>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9+ 7;
const int INF = numeric_limits<int>::max() - 1e8;
const ll INFLL = numeric_limits<ll>::max() - 1e17;

signed main() {
    ll k, q;
    cin >> k >> q;
    vector<ll> d(k);
    for (int i = 0; i < k; i++) cin >> d[i];
    for (int i = 0; i < q; i++) {
        ll n, x, m;
        cin >> n >> x >> m;
        ll sum = 0, zero = 0, dSum = 0, zeroSum = 0;
        vector<ll> base(k);
        n--;
        for (int j = 0; j < k; j++) {
            base[j] = d[j] % m;
            if (base[j] == 0) zeroSum++;
            dSum += base[j];
        }
        sum = dSum * (n / k);
        zero = zeroSum * (n / k);
        for (int j = 0; j < n % k; j++) {
            sum += base[j];
            if (base[j] == 0) zero++;
        }
        sum += (x % m);
        cout << n - (sum / m) - zero << endl;
    }
}
