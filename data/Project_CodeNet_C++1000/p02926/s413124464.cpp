#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

ostream& operator<<(ostream& os, Pll& a)
{
    return os << a.first << " " << a.second;
}

template <class T>
void debug(T& v)
{
    for(auto& x: v) cout << x << endl;
    cout << endl;
}

bool compAngle(Pll& a, Pll& b)
{
    return atan2(a.second, a.first) < atan2(b.second, b.first);
}

ll norm2(ll& X, ll& Y)
{
    return X*X + Y*Y;
}

int main()
{
    int N;
    cin >> N;
    vector<Pll> vecs(N);
    for(auto& v: vecs) cin >> v.first >> v.second;
    sort(vecs.begin(), vecs.end(), compAngle);
    // debug(vecs);

    vector<ll> sx(N+1), sy(N+1);
    sx[0] = 0;
    sy[0] = 0;
    for(int i=0; i<N; i++){
        sx[i+1] = sx[i] + vecs[i].first;
        sy[i+1] = sy[i] + vecs[i].second;
    }

    ll ans = norm2(sx[N], sy[N]);
    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            ll X = sx[j+1] - sx[i];
            ll Y = sy[j+1] - sy[i];
            ans = max(ans, norm2(X, Y));
            X = sx[N] - X;
            Y = sy[N] - Y;
            ans = max(ans, norm2(X, Y));
        }
    }

    cout << fixed << setprecision(20) << sqrt(ans) << endl;
}