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
using ld = long double;
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
    ll iA, iB, iH, iM;
    cin >> iA >> iB >> iH >> iM;
    ld A = ld(iA);
    ld B = ld(iB);
    ld H = ld(iH);
    ld M = ld(iM);
    ld dt = (H / 12.0L + M / (60.0L * 12.0L) - M / 60.0L) * 2.0L * M_PI;
    ld R2 = A * A + B * B - 2.0L * A * B * cosl(dt);
    ld R = sqrtl(R2);
    printf("%16.16Lf", R);
    return 0;
}