//
#define _USE_MATH_DEFINES
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
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);++i)
inline void yes(bool cond) { cond ? puts("Yes") : puts("No"); }
template<typename Type> inline void chmin(Type& a, Type b) { if (a > b) a = b; }
template<typename Type> inline void chmax(Type& a, Type b) { if (a < b) a = b; }
template<typename Type> inline void sort(Type& arr) { std::sort(arr.begin(), arr.end()); }
template<typename Type> inline Type nth(vector<Type>& arr, size_t pos) { std::nth_element(arr.begin(), arr.begin() + pos, arr.end()); return arr[pos]; }
#define BIGP   1000000007
#define INF_I  std::numeric_limits<ll>::max()
#define INF_F  std::numeric_limits<float>::infinity()
#define PI  3.1415926535
//
#include <iomanip>
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    ;

    ll A, B, H, M;
    cin >> A >> B >> H >> M;
    using ld = double;
    ld hd = ld(H / ld(12.0) + ld(M) / (ld(60.0)* ld(12.0))) *ld(2.0) * ld(M_PI);
    ld md = ld(M / ld(60.0)) * ld(2.0) * ld(M_PI);
    ld ax = ld(A) * cos(hd);
    ld ay = ld(A) * sin(hd);
    ld bx = ld(B) * cos(md);
    ld by = ld(B) * sin(md);
    ld dx = ax - bx;
    ld dy = ay - by;
    ld len = sqrtl(dx * dx + dy * dy);
    cout << std::setprecision(16) << len;
    return 0;
}