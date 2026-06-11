#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
typedef pair<long double, int> d_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int N;
int x[105], y[105];
long double ans;
vector<d_i> v;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> x[i] >> y[i];
        long double theta = atan2(x[i], y[i]);
        v.push_back({theta, i});
        v.push_back({theta + 2 * PI, i});
    }
    sort(v.begin(), v.end());
    for(int l = 0; l < v.size(); l++) {
        for(int r = l + 1; r < v.size(); r++) {
            if(r - l > N) break;
            long double now = 0;
            long double X = 0;
            long double Y = 0;
            for(int i = l; i < r; i++) {
                int index = v[i].second;
                X += x[index];
                Y += y[index];
            }
            chmax(ans, pow(X*X+Y*Y, 0.5));
        }
    }
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}
