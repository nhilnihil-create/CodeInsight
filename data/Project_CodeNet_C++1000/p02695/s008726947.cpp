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
inline void yes(bool cond) { cond ? puts("YES") : puts("NO"); }
template<typename Type> inline void chmin(Type& a, Type b) { if (a > b) a = b; }
template<typename Type> inline void chmax(Type& a, Type b) { if (a < b) a = b; }
template<typename Arr, typename Type> inline void fill(Arr& arr, Type v) { std::fill(arr.begin(), arr.end(), v); }
template<typename Type> inline void sort(Type& arr) { std::sort(arr.begin(), arr.end()); }
template<typename Type> inline Type nth(vector<Type>& arr, size_t pos) { std::nth_element(arr.begin(), arr.begin() + pos, arr.end()); return arr[pos]; }
template<typename Type> inline void unique(Type& arr) { sort(arr); arr.erase(unique(arr.begin(), arr.end()), arr.end()); }
constexpr double BIGP = 1000000007L;
constexpr ll INF_I = std::numeric_limits<ll>::max();
constexpr double INF_F = std::numeric_limits<float>::infinity();
constexpr double PI = 3.14159265358979323846L;

//
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    //
    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<ll> a(Q);
    vector<ll> b(Q);
    vector<ll> c(Q);
    vector<ll> d(Q);
    rep(i, Q) cin >> a[i] >> b[i] >> c[i] >> d[i];
    //
    ll mx = 0;
    const auto check = [&](std::array<int,10> A)
    {
        if (M < A[N - 1]) return;
        ll score = 0;
        rep(i,Q) if (A[b[i]-1] - A[a[i] - 1] == c[i]) score += d[i];
        chmax(mx, score);
    };
    // 
    for (int i1 = 1; i1 <= 10; ++i1)
        for (int i2 = i1; i2 <= 10; ++i2)
            for (int i3 = i2; i3 <= 10; ++i3)
                for (int i4 = i3; i4 <= 10; ++i4)
                    for (int i5 = i4; i5 <= 10; ++i5)
                        for (int i6 = i5; i6 <= 10; ++i6)
                            for (int i7 = i6; i7 <= 10; ++i7)
                                for (int i8 = i7; i8 <= 10; ++i8)
                                    for (int i9 = i8; i9 <= 10; ++i9)
                                        for (int i10 = i9; i10 <= 10; ++i10)
                                            check({ i1,i2, i3, i4, i5, i6, i7, i8, i9, i10 });

    cout << mx;

    return 0;
}