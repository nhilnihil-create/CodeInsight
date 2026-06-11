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

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

template <class T>
void debug(T& v)
{
    for(auto& x: v) cout << x << " ";
    cout << endl;
}

int main()
{
    ll M;
    cin >> M;
    vector<ll> d(M), c(M);
    for(int i=0; i<M; i++) cin >> d[i] >> c[i];

    ll s = 0, n = 0;
    for(int i=0; i<M; i++){
        s += d[i] * c[i];
        n += c[i];
    }

    ll ans = n-1+s/9;
    if(s%9==0) ans--;
    cout << ans << endl;
}