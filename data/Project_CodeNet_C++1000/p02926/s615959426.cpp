#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e18;

int main(){
    int N;
    cin >> N;
    double x[N], y[N], arg[N];
    vector<pair<double, int> >vec;
    rep(i, N){
        cin >> x[i] >> y[i];
        arg[i] = atan2(y[i], x[i]);
        vec.push_back(make_pair(arg[i], i));
    }
    sort(vec.begin(), vec.end());
    double M = 0;
    rep(i, N){
        rep(j, N+1){
            double X = 0, Y = 0, R;
            rep(k, j){
                int l = vec[(i+k)%N].second;
                X += x[l];
                Y += y[l];
            }
            R = sqrt(X*X+Y*Y);
            M = max(M, R);
        }
    }
    cout << setprecision(30) << M << endl;
}