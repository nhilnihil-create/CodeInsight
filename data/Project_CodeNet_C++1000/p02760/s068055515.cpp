//
#include <vector>
#include <set>
#include <array>
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <numeric>
#include <bitset>
//
using ll = long long;
using ld = long double;
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);++i)
inline void yes(bool cond) { cond ? puts("Yes") : puts("No"); }
template<typename Type> inline void chmin(Type& a, Type b) { if (a > b) a = b; }
template<typename Type> inline void chmax(Type& a, Type b) { if (a < b) a = b; }
template<typename Arr, typename Type> inline void fill(Arr& arr, Type v) { std::fill(arr.begin(), arr.end(), v); }
template<typename Type> inline void sort(Type& arr) { std::sort(arr.begin(), arr.end()); }
template<typename Type> inline Type nth(vector<Type>& arr, size_t pos) { std::nth_element(arr.begin(), arr.begin() + pos, arr.end()); return arr[pos]; }
constexpr double BIGP = 1000000007L;
constexpr double INF_I = std::numeric_limits<double>::max();
constexpr double INF_F = std::numeric_limits<float>::infinity();
constexpr double PI = 3.14159265358979323846L;
//
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    ll A[9] = {0};
    bool B[9] = { 0 };
    rep(i, 9) cin >> A[i];
    ll N;
    cin >> N;
    rep(i, N)
    {
        ll b;
        cin >> b;
        rep(j, 9)
        {
            if (A[j] == b) 
                B[j] = true;
        }
    }
    //
    yes(// 横
        (B[0] && B[1] && B[2]) ||
        (B[3] && B[4] && B[5]) ||
        (B[6] && B[7] && B[8]) ||
        // 縦
        (B[0] && B[3] && B[6]) ||
        (B[1] && B[4] && B[7]) ||
        (B[2] && B[5] && B[8]) ||
        // 斜め
        (B[0] && B[4] && B[8]) ||
        (B[2] && B[4] && B[6]));
    //
    return 0;
}