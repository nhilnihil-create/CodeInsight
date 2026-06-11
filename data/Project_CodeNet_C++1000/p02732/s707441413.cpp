#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#ifdef LOCAL
#include<debug.h>
#else
#define db(...) 21
#endif
#define sz(a) (int)a.size()
#define found(m,x) ((m).find(x)!=(m).end())
#define uset unordered_set
#define umap unordered_map
#define a(x) x.begin(),x.end()
#define fo(i,n) for(int i=0;i<(int)n;i++)
#define Fo(i,k,n) for(int i=k;k<n?i<=(int)n:i>=(int)n;k<n?i++:i--)
#define input(v,n) fo(i,n)cin>>v[i]
using vi = vector<int>;
using vpi = vector<pair<int,int>>;
using pi = pair<int,int>;

const int nax = 1e5+7;
const int mod = 1e9+7; //1e9+2667 :: 0xcf : inf, 0xc0 -inf
const int inf = numeric_limits<int> :: max() - (int)9e6;
// ===================== MANASH =================== //

void test() {

    int n;
    cin >> n;
    map<int,int> m;
    vi v(n);
    fo(i,n) {
        int t;
        cin >> t;
        v[i] = t;
        m[t]++;
    }
    int s = 0;
    for( pi p : m ) {
        int y = p.second;
        s += max(0LL,y*(y-1)/2);
    }
    for( int i = 0; i < n; i++) {
        int y = m[v[i]];
        cout << max(0LL,(s - y + 1)) << '\n';
    }
}

signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif

    int T = 1;
    //cin >> T;
    while(T--) {
        test();
        cout << "\n";
    }
    return 0;

}