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
//
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    //
    ll N, R;
    cin >> N >> R;
    if (10 <= N)
    {
        cout << R;
    }
    else
    {
        cout << R + 100 * (10 - N);
    }
    return 0;
}