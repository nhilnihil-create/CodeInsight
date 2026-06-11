#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
#define all(n) begin(n), end(n)
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef unsigned long long ull;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts)
{
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }

template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v)
{
    for (auto &e : t)
        fill_v(e, v);
}
ll p(ll a,ll b){return a+b;}
ll e(){return 0;};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vll a(n);
    
    for (size_t i = 0; i < n; i++)
    {
        
        cin >> a[i];

    }
    atcoder::segtree<ll,p,e> seg(a);
    for (size_t i = 0; i < q; i++)
    {
        int t,a,b;
        cin>>t>>a>>b;
        if(t)
        {
            cout<<seg.prod(a,b)<<'\n';
        }
        else
        {
            seg.set(a,seg.get(a)+b);
        }
        
    }
    
    
    
    return 0;
}