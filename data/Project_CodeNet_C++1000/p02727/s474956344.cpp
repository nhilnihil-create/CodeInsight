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
// typedef pair<int,int> pi;

const int nax = 1e5+7;
const int mod = 1e9+7; //1e9+2667
const int inf = numeric_limits<int> :: max();
// ===================== MANASH =================== //

void test() {

    
    int x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;
    vector<int> red(a),green(b),ls(c);
    fo(i,a) cin >> red[i]; 
    fo(i,b) cin >> green[i];
    fo(i,c) cin >> ls[i];

    sort(a(red),greater<int>());
    sort(a(green),greater<int>());
    sort(a(ls),greater<int>());

    while((int)red.size() > x ) red.pop_back();
    while((int)green.size() > y ) green.pop_back();

    vector<int> f(a(red));

    f.insert(f.end(),a(green));
    f.insert(f.end(),a(ls));
    // db(f);
    sort(a(f),greater<int>());
    cout << accumulate(f.begin(),f.begin()+x+y,0LL);
    
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