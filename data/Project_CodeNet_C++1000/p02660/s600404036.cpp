#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e6;
const ll inf = 1e9;
const double pi = acos(-1);
ll sieve[maxn+5] = {0};
int main(){
    ll n;
    cin>>n;
    sieve[1] = 1;
    sieve[0] = 1;
    loop(i,2,maxn){
        if(sieve[i]){
            continue;
        }
        for(ll j =2;j*i<=maxn;j++){
            sieve[j*i] = 1;
        }
    }
    if(n==0 || n==1){
        cout<<0<<endl;
        return 0;
    }
    ll ans = 0;
    ll i = 2;
    while(i<=n || n==1){
        if(i>maxn){
            break;
        }
        if(n%i || sieve[i]==1){
            i++;
            continue;
        }
        ll count = 0;
        ll tar = 1;
        while(n%i==0){
            n/=i;
            count++;
            if(count==tar){
                count=0;
                ans++;
                tar++;
            }
        }
        i++;
    }
    if(n>maxn){
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}