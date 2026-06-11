#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

template <typename T, typename U> std::istream&operator>>(std::istream&i, pair<T,U>&p) {i >> p.x >> p.y; return i;}
template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}
template <typename T, typename U> std::ostream&operator<<(std::ostream&o, const pair<T,U>&p) {o << p.x << ' ' << p.y; return o;}
template<typename T>std::ostream&operator<<(std::ostream&o,const vector<T>&t) {if(t.empty())o<<'\n';for(size_t i=0;i<t.size();++i){o<<t[i]<<" \n"[i == t.size()-1];}return o;}

#define deb(x) cout << '>' << #x << ':' << x << endl;
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define END '\n'
#define inf 9e18
#define ff first
#define ss second
#define pb push_back
const int maxN = 1e6;
ll sv[maxN + 1];

void solve(){
    int n;
    cin >> n;
    vi A(n);
    cin >> A;
    vi cnt(maxN + 1, 0);
    int g = A[0];
    for (int i = 0; i < n; ++i) {
        g = __gcd(A[i], g);
        while(A[i] > 1) {
            int m = sv[A[i]];
            ++cnt[m];
            while(A[i] % m == 0) A[i] /= m;
        }
    }
    bool ok = true;
    for (int i = 0; i <= maxN; ++i) {
        if (cnt[i] > 1) {
            ok = false;
        }
    }
    if (ok) {
        cout << "pairwise coprime" << END;
    } else if (g == 1) {
        cout << "setwise coprime" << END;
    } else cout << "not coprime" << END;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (ll i = 1; i <= maxN; ++i) sv[i] = i;
    for (ll i = 2; i * i <= maxN; ++i) {
        if (sv[i] != i) continue;
        for (ll j = i * i; j <= maxN; j += i) {
            if (sv[j] == j) sv[j] = i; 
        }
    }
    while(t--){
        solve();
    }
    return 0;
}