//
#include <vector>
#include <set>
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
    string S, T, U;
    ll A, B;
    cin >> S >> T;
    cin >> A >> B;
    cin >> U;
    //
    if (S == U) --A;
    if (T == U) --B;
    cout << A << " "<<B;

    return 0;
}