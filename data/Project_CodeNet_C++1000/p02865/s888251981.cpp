#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 
 
//using namespace __gnu_pbds;
using namespace std;
 
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define NULL 0
#define pi 3.14159265358979323846
#define all(x) x.begin(), x.end()
#define d0(x) cout<<x<<" ";
#define d1(x) cout<<x<<"\n";
#define d2(x,y) cout<<x<<" "<<y<<"\n";
#define d3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n";
#define d4(x,y,z,w) cout<<x<<" "<<y<<" "<<z<<" "<<w<<"\n";
 
//#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> 
//#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
 
template<typename T, typename U> static inline void amin(T &x, U y){if (y < x)x = y;} 
template<typename T, typename U> static inline void amax(T &x, U y){if (y > x)x = y;} 
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
const  ll mod= 1000000007  ; 
const long long inf = (ll)1e18+17;
const int inff = 1500000000;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};


void solve(){ 
    ll n;cin>>n;
    if(n%2==0){
        n=n/2-1;
        cout<<n<<endl;return;
    }
cout<<n/2<<endl;
}
 
int main()
{  
    clock_t tt;tt = clock(); 
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    //pre();
    for(int i=1;i<=t;i++){
       //cout<<"Case #"<<i<<": ";
       solve();
    }
    tt = clock() - tt; double time_taken = ((double)tt)/CLOCKS_PER_SEC;   
    //printf("code took %f seconds to execute \n", time_taken); 
    return 0;
}
 
// ============== Notes =============== //
// common bugs
// - remove ios_base for interactive problems
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases
