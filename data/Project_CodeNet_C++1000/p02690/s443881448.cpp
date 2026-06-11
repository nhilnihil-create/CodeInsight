#include <bits/stdc++.h>
using namespace std;
#define inf 2000000000
#define INF 1e18
typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define getbit(n,i) (((n)&(1LL<<(i)))!=0)
#define setbit0(n,i) ((n)&(~(1LL<<(i))))
#define setbit1(n,i) ((n)|(1LL<<(i)))
#define togglebit(n,i) ((n)^(1LL<<(i)))
#define lastone(n) ((n)&(-(n)))
#define read freopen("debug\\in.txt","r",stdin)
#define write freopen("debug\\out.txt","w",stdout)
#define fi first
#define se second
#define getI(a) scanf("%d",&a)
#define getII(a,b) scanf("%d%d",&a,&b)
#define PI (acos(-1))
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod (1000000007)
#define asz 500005
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define pf push_front
ll a[100005];
int main()
{
    fastread;
     ll i,j,k,n,m,y,t;
    cin>>n;
   // m=(ll)(pow(n,1/5));
    //cout<<m;
    ll res;
   for(i=-150;i<=150;i++){
   // k=(ll)(pow(i,5));
   for(j=-150;j<=150;j++){
    res=(i*i*i*i*i)-(j*j*j*j*j);
    if(res==n){
        cout<<i<<" "<<j;
        return 0;
              }
         }
     }
   return 0;
}
