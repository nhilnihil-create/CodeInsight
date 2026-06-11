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

int n;

void test() {

    int m;
    cin >> n >> m;
    cout << n*(n-1)/2 + m*(m-1)/2;
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