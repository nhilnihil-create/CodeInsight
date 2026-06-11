#include <bits/stdc++.h>

// #define DEBUG 1

#define int long long
#define int long long
#define for0(i,n) for (int i=0; i<n; i++)
#define fill1(a,z) fill_n(a, sizeof(a)/sizeof(a[0]), z)
#define fill2(a,z) fill_n(a[0], sizeof(a)/sizeof(a[0][0]), z)
#define fill3(a,z) fill_n(a[0][0], sizeof(a)/sizeof(a[0][0][0]), z)
#define mp make_pair
#define X first
#define Y second
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define all(a) a.begin(),a.end()
#define sz(x) (int)(x).size()
#define pmod(x,m) (((x)%(m)+m)%m)
#ifdef int
#define read(x) scanf("%lld",&x);
#else
#define read(x) scanf("%d",&x);
#endif

#ifdef DEBUG
#define nl cout<<"\n";
#define pr(x) cout<<(x)<<" ";
#define prl(x) cout<<#x " = "<<x<<endl;
#define prp(x) cout<<"("<<(x).first<<" "<<(x).second<<") ";
#define printv(v) {for(int _=0; _<sz(v); _++) cout<<v[_]<<" "; cout<<"\n";}
#define printa(a,s) {for (int _=0; _<s; _++) cout<<a[_]<<" "; cout<<"\n";}
#define print2D(a,m,n) {for (int _=0; _<m; _++) {for (int __=0; __<n; __++) cout<<a[_][__]<<" "; cout<<"\n";} cout<<"\n";}
#define priter(v) {for (auto x : v) {pr(x)} nl}
#define debug cout<<"ok at line "<<__LINE__<<endl;
#else
#define nl
#define pr(x)
#define prl(x)
#define prp(x)
#define printv(v)
#define printa(a,s)
#define print2D(a,m,n)
#define priter(v)
#define debug
#endif
#define MAXN 100000

using namespace std;

typedef long long ll;
typedef pair<int,int> edge; 

const int INF = 2147483647;
const long long INFL = 9223372036854775807LL;
const double EPSILON = 0.00000001;
const long long MOD = 1000000007;

void build_odd_tree(int n, int offset, vector<edge>& edges) 
{
    for (int i=2; i<=n; i++) {
        edges.push_back({1,i}); 
        edges.push_back({i,(i^1)+offset}); 
    }   
    edges.push_back({3+offset, 1+offset}); 
}

int32_t main()
{
    #ifdef DEBUG
    //freopen("C.txt","r",stdin);
    //freopen("","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; 
    cin >> n; 
    vector<edge> edges; 
    
    if (n < 3) {
        cout << "No" << endl; 
        return 0; 
    }
    else if (n%2 == 1) {
        build_odd_tree(n, n, edges); 
    }
    else if (n%2 == 0) {
        build_odd_tree(n-1, n, edges); 
        
        
        // find first 1 bit 
        int bit = 0; 
        for (; bit <= 20; bit++) {
            if (n & (1<<bit)) 
                break; 
        }
        int a = 1<<bit; 
        int b = n ^ a; 
        if (b == 0) {
            // means n is a power of 2 
            cout << "No" << endl; 
            return 0; 
        }
        // connect n nodes through the path n -- a -- 1 -- 1^b -- n
        edges.push_back({a,n}); 
        edges.push_back({1^b, n+n});   
    }
    
    cout << "Yes" << endl; 
    for (edge e : edges) {
        cout << e.first << " " << e.second << endl;
    }
    return 0;
}
