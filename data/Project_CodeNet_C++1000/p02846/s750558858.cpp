#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9 + 7;
const int INF = 9e18;

signed main(){
    vector<int> T(2), A(2), B(2), dif(2);
    cin >> T >> A >> B;
    for (int i = 0; i <= 1; i++) {
        A[i] *= T[i];
        B[i] *= T[i];
        dif[i] = B[i] - A[i];
    }
    if ((dif[0] < 0 && dif[1] < 0) || (dif[0] > 0 && dif[1] > 0)) {
        cout << 0 << endl;
        return 0;
    }
    if (dif[0] < 0 && dif[1] > 0) {
        dif[0] *= -1;
        dif[1] *= -1;
    }
    int next = dif[0] + dif[1];
    if (next > 0) {
        cout << 0 << endl;
        return 0;
    } else if (next == 0) {
        cout << "infinity" << endl;
        return 0;
    }
    int ans = (dif[0] / abs(next)) * 2 + (dif[0] % abs(next) != 0);
    cout << ans << endl;
}
