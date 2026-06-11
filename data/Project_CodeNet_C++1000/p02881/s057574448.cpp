#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double db;
typedef std::string str;
#define sei set<int>
#define sell set<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vld vector<ld>
#define vstr vector<str>
#define vpii vector<pii>
#define vpll vector<pll>
#define all(v) v.begin(),v.end()
#define foa(i,v) for(auto i : v)
#define fo(i,a,b) for(int i=a;i<b;i++)
#define fo_(i,a,b) for(int i=a;i>b;i--)
#define M(a) memset(a,0,sizeof a)
#define M_(a) memset(a ,-1,sizeof a)
#define deb(x)  cerr << #x << " = " << x << endl
#define pb push_back
#define pob pop_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define OK order_of_key
#define FO find_by_order
#define nmax 1000100
const ld PI = 3.141592653589793238462643383279;
const ll inf = std::numeric_limits<ll>::max();
const int infint = std::numeric_limits<int>::max();
const ll mod = 1e9+7;
using namespace __gnu_pbds;
using namespace std;
/*#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")*/
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vll divs(ll n){
    vll out;
    fo(i,1,sqrt(n)+1){
        if(n%i == 0 && n/i != i){
            out.pb(i);
            out.pb(n/i);
        }else if(n%i == 0 && n/i == i) out.pb(i);
    }
    sort(out.begin(),out.end());
    return out;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    ll ans = n-1;
    foa(i,divs(n)){
        ans = min(ans,i-1+n/i-1);
    }
    cout << ans;

    return 0;
}

