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

ll N, M, Q;
vector<ll> a;
vector<ll> b;
vector<ll> c;
vector<ll> d;
ll mx = 0;
//
void check(std::vector<ll> A)
{
    ll score = 0;
    rep(i, Q) if (A[b[i] - 1] - A[a[i] - 1] == c[i]) score += d[i];
    chmax(mx, score);
}
void dfs(std::vector<ll> A)
{
    if (A.size() == N)
    {
        check(A);
        return;
    }
    A.push_back(A.back());
    while (A.back() != M)
    {
        dfs(A);
        ++A.back();
    }
    dfs(A);
}
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    //
    cin >> N >> M >> Q;
    a = b = c = d = vector<ll>(Q);
    rep(i, Q) cin >> a[i] >> b[i] >> c[i] >> d[i];
    //
    dfs({1});
    cout << mx;
    return 0;
}