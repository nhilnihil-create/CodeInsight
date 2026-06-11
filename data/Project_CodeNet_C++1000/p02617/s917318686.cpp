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
#include <functional>
#include <map>
#include <cstdlib>
#include <stack>
#include <cassert>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;
using Graph = Vvec<int>;

template <class T>
void debug(T& v)
{
    for(auto& x: v) cout << x << " ";
    cout << endl;
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> u(N-1), v(N-1);
    for(int i=0; i<N-1; i++) cin >> u[i] >> v[i];

    ll ans = N * (N+1) * (N+2) / 6;
    for(int i=0; i<N-1; i++){
        if(u[i] > v[i]) swap(u[i], v[i]);
        ans -= u[i] * (N - v[i] + 1);
    }
    cout << ans << endl;
}