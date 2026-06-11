#include <bits/stdc++.h>
#define fir first
#define sec second
#define pb 	push_back
#define ll  long long
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define debug(x) cerr<<#x<<" =: "<<x<<endl;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define Find find_by_order
#define Order order_of_key
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 mrand(random_device{}());
ll rnd(ll x) { return mrand() % x;}
ll ksm(ll a,ll b,ll mod){ll ans=1;a%=mod;while(b){if(b&1) ans=ans*a%mod;b>>=1;a=a*a%mod;}return ans;}
ll phi(ll n){ll ans=n;for(ll i=2;i*i<=n;i++){if(n%i==0) {while(n%i==0) n/=i;ans=ans*(i-1)/i;}}if(n>1) ans=ans*(n-1)/n;return ans;}
//head

const int maxn = 1e6 + 7;
vector<int> vec[maxn];
int a[maxn], ans[maxn];
set<int> s;

int main (){
    int s, w;
    cin >> s >> w;
    if (s <= w) cout << "unsafe\n";
    else cout << "safe\n";
    return 0;
}
