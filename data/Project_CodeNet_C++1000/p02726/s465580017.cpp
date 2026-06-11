#include<bits/stdc++.h>
using namespace std;
#define int long long
#ifdef LOCAL
#include<debug.h>
#else
#define db(...) 21
#endif
#define found(m,x) ((m).find(x)!=(m).end())
#define uset unordered_set
#define umap unordered_map
#define a(x) x.begin(),x.end()
#define fo(i,n) for(int i=0;i<(int)n;i++)
#define Fo(i,k,n) for(int i=k;k<n?i<=(int)n:i>=(int)n;k<n?i++:i--)
#define input(v,n) fo(i,n)cin>>v[i]
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pi;

const int nax = 1e5+7;
const int mod = 1e9+7; //1e9+2667
const int inf = numeric_limits<int> :: max();
// ===================== MANASH =================== //

int n,m;

void test() {

    int x,y;
    cin >> n >> x >> y;
    vector<int> len(n+1);
    for( int i = 1; i <= n; i++) {
        for( int j = i+1; j <= n; j++) {
            int dist = min(abs(j-i),abs(i-x) + 1 + abs(y-j));
            len[dist]++;
        }
    }
    Fo(i,1,n-1) cout << len[i] << '\n';
}

signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    cout<<"Time Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec.\n";
    #endif

    int T = 1;
    //cin >> T;
    while(T--) {
        test();
        cout << "\n";
    }
    return 0;

}