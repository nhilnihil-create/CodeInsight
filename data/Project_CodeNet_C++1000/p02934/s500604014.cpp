//
#include <vector>
#include <set>
#include <map>
#include <array>
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <numeric>
#include <bitset>
//
using ll = long long;
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);++i)
inline void yes(bool cond) { cond ? puts("Yes") : puts("No"); }
template<typename Type> inline void chmin(Type& a, Type b) { if (a > b) a = b; }
template<typename Type> inline void chmax(Type& a, Type b) { if (a < b) a = b; }
template<typename Arr, typename Type> inline void fill(Arr& arr, Type v) { std::fill(arr.begin(), arr.end(), v); }
template<typename Type> inline void sort(Type& arr) { std::sort(arr.begin(), arr.end()); }
template<typename Type> inline Type nth(vector<Type>& arr, size_t pos) { std::nth_element(arr.begin(), arr.begin() + pos, arr.end()); return arr[pos]; }
constexpr double BIGP = 1000000007L;
constexpr double INF_I = std::numeric_limits<ll>::max();
constexpr double INF_F = std::numeric_limits<float>::infinity();
constexpr double PI = 3.14159265358979323846L;
//
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    double ans = 0.0;
    rep(i, N)
    {
        ans += 1.0 / double(A[i]);
    }
    ans = 1.0 / ans;
    printf("%.6f", ans);

#if 0
    if (A.size() == 1)
    {
        printf("%.6f", A[0]);
        return 0;
    }

    // 分母を求める
    ll tmp = lcm(A[0], A[1]);
    rep(i,N-2)
    {
        tmp = lcm(tmp, A[i+2]);
    }
    //
    ll denom = 0;
    rep(i, N)
    {
        denom += tmp/A[i];
    }
    double ans = double(tmp)/double(denom);
    printf("%.10f",ans);
#endif

    //
    return 0;
}