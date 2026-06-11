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
#include <iomanip>
//
using ll = long long;
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);++i)
#define outD(fpv) cout << setprecision(20) << fpv << endl;
inline void yes(bool cond) { cond ? puts("Yes") : puts("No"); }
inline void YES(bool cond) { cond ? puts("YES") : puts("NO"); }
template<typename Type> inline void chmin(Type& a, Type b) { if (a > b) a = b; }
template<typename Type> inline void chmax(Type& a, Type b) { if (a < b) a = b; }
template<typename Arr, typename Type> inline void fill(Arr& arr, Type v) { std::fill(arr.begin(), arr.end(), v); }
template<typename Type> inline void sort(Type& arr) { std::sort(arr.begin(), arr.end()); }
template<typename Type> inline void reverse(Type& arr) { reverse(arr.begin(), arr.end()); }
template<typename Type> inline Type nth(vector<Type>& arr, size_t pos) { std::nth_element(arr.begin(), arr.begin() + pos, arr.end()); return arr[pos]; }
template<typename Type> inline void unique(Type& arr) { sort(arr); arr.erase(unique(arr.begin(), arr.end()), arr.end()); }
constexpr ll INF_I = std::numeric_limits<ll>::max();
constexpr ll BIGP = 1e9 + 7;
constexpr double INF_F = std::numeric_limits<float>::infinity();
constexpr double PI = 3.14159265358979323846L;
using P = pair<ll, ll>;
//
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    //
    ll N;
    cin >> N;
    using XYS = vector<P>;
    vector<ll> A(N);
    vector<XYS> xys(N);
    rep(i, N)
    {
        cin >> A[i];
        vector<P> xy(A[i]);
        rep(j, A[i])
        {
            P p;
            cin >> p.first >> p.second;
            --p.first;
            xy[j] = p;
        }
        xys[i] = xy;
    }
    //
    uint16_t maxBit = 1 << N;
    vector<int32_t> buffer(N,-1);
    ll maxSyojiki = 0;
    for (uint16_t bits = 0; bits < maxBit; ++bits)
    {
        bool valid = true;
        //
        for (int mi = 0; mi < N; ++mi)
        {
            //
            auto& xy = xys[mi];
            // 正直者の場合
            if (bits & (1 << mi))
            {
                for(auto& p: xy)
                {
                    bool t = (bits & (1 << p.first));
                    if (p.second != t)
                    {
                        valid = false;
                        goto EXIT;
                    }
                }
            }
        }
    EXIT:
        if (valid)
        {
            ll count = 0;
            rep(i,N)
            {
                if (bits & (1 << i)) ++count;
            }
            chmax(maxSyojiki, count);
        }
    }
    cout << maxSyojiki;

    //
    return 0;
}