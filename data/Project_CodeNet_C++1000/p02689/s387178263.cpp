//
#include <vector>
#include <set>
#include <map>
#include <array>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <bitset>
#include <cstdio>
#include <cstdint>
#include <cmath>
//
using ll = long long;
using ld = long double;
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);++i)
inline void yes(bool cond) { cond ? puts("Yes") : puts("No"); }
template<typename Type> inline void chmin(Type& a, Type b) { if (a > b) a = b; }
template<typename Type> inline void chmax(Type& a, Type b) { if (a < b) a = b; }
template<typename Type> inline void sort(Type& arr) { std::sort(arr.begin(), arr.end()); }
template<typename Type> inline Type nth(vector<Type>& arr, size_t pos) { std::nth_element(arr.begin(), arr.begin() + pos, arr.end()); return arr[pos]; }
constexpr ll BIGP = 1000000007L;
constexpr ll INF_I = std::numeric_limits<ll>::max();
constexpr ld INF_F = std::numeric_limits<float>::infinity();
constexpr ld PI = 3.14159265358979323846L;
//
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<ll> H;
    rep(i, N)
    {
        ll h;
        cin >> h;
        H.push_back(h);
    }
    vector<bool> h(N, true);
    rep(i, M)
    {
        ll a,b;
        cin >> a >> b;
        --a;
        --b;
        if (H[a] <= H[b]) h[a] = false;
        if (H[a] >= H[b]) h[b] = false;
    }
    ll ans = 0;
    rep(i, N)if (h[i]) ++ans;
    cout << ans;
    return 0;
}