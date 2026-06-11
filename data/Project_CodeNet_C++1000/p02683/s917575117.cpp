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
template<typename Type> inline void sort(Type& arr) { std::sort(arr.begin(), arr.end()); }
template<typename Type> inline Type nth(vector<Type>& arr, size_t pos) { std::nth_element(arr.begin(), arr.begin() + pos, arr.end()); return arr[pos]; }
constexpr ll BIGP = 1000000007L;
constexpr ll INF_I = std::numeric_limits<ll>::max();
constexpr ld INF_F = std::numeric_limits<float>::infinity();
constexpr ld PI    = 3.14159265358979323846L;
//
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    ll N, M, X;
    cin >> N >> M >> X;
    //
    struct Book
    {
    public:
        // price
        ll C;
        // skill
        std::vector<ll> A;
    };
    //
    vector<Book> books;
    rep(i, N)
    {
        Book book;
        cin >> book.C;
        rep(j, M)
        {
            ll a;
            cin >> a;
            book.A.push_back(a);
        }
        books.push_back(book);
    }
    //
    std::vector<ll> skills(N,0);
    uint16_t total = 1 << N;
    ll minCost = std::numeric_limits<ll>::max();
    for (uint16_t bits = 0; bits < total; ++bits)
    {
        // 
        std::fill(skills.begin(), skills.end(), 0);
        uint16_t b = bits;
        ll cost = 0;
        rep(i,N)
        {
            if (b & 1)
            {
                auto& book = books[i];
                cost += book.C;
                rep(j, M)
                {
                    skills[j] += book.A[j];
                }
            }
            b >>= 1;
        }
        //
        bool valid = true;
        rep(i, M)
        {
            valid &= (skills[i] >= X);
        }
        if (valid && (cost < minCost))
        {
            minCost = cost;
        }
    }
    if (minCost == std::numeric_limits<ll>::max())
    {
        cout << -1;
    }
    else
    {
        cout << minCost;
    }

    return 0;
}