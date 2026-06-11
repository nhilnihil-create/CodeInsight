#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#include <set>
#include <iterator>
using namespace std;
using namespace __gnu_pbds;


#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()

#define ll long long int
#define vi vector<int>
#define vii vector<pair<int,int> >
#define pii pair<int,int>
#define plii pair<pair<ll, int>, int>
#define piii pair<pii, int>
#define viii vector<pair<pii, int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define mp make_pair
#define ms(x, v) memset(x, v, sizeof x)
#define pr_vec(v) for(int i=0;i<v.size();i++) cout << v[i] << " " ;

#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)

#define INF INT_MAX
#define matrix vector<vector<ll> >

#define fr(i, a, b) for(i=a; i<=b; i++)
#define fb(i, a, b) for(i=a; i>=b; i--)
#define ASST(x, l, r) assert( x <= r && x >= l )
#define maxbits 22
#define maxmask (1ll<<maxbits)
typedef tree<pll, null_type, less<pll>, rb_tree_tag,
             tree_order_statistics_node_update>
    new_data_set;
const int  N=100000 +10, M=(ll)1e9+1 ;
 const int mod =(ll)1e9+7,sz=5 ;

 ll n;
map<ll,ll> m;
void comp(ll x){
    cout << 3 << " " << n+1 << "\n";
    for(ll i=3;i<=x;i+=2){
        m[i+n]++;
        m[i-1]++;
        cout << 1 << " " << i+n << "\n";
        cout << 1 << " " << i-1 << "\n";
        cout << i << " " << i-1 << "\n";
        cout << i+n << " " << i-1+n << "\n";
    }
}

void work(){
    cin >> n;
    if((n&(n-1))==0){
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    if(n&1)
        comp(n);
    else{
        comp(n-1);
        ll x=n^1;
        ll a,b,k=log2(x);
        a=(1ll<<k);
        b=x^a;
        if(m[a]!=0)
            cout << a << " " << n << "\n";
        else
            cout << a+n << " " << n << "\n";
        if(m[b]!=0)
            cout << b << " " << 2*n << "\n";
        else
            cout << b+n << " " << 2*n << "\n";
    }
}
int main(){
 ios_base::sync_with_stdio(0);
// cin.tie(0);
    ll t;
//    cin >> t;
    t=1;
    while(t--){
            work();
    }
   return 0;

}
