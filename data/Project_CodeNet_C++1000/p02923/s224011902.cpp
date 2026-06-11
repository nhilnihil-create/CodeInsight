#include<bits/stdc++.h>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
//lower_bound like o_set.find_by_order(val) strictly less then val
//upper_bound like o_set.order_of_key(MAX)– o_set.order_of_key(val)
//if u need multiset elements then use second parameter as time and think 
//typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_popcountll(x)
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define se second
#define fi first
#define pai acos(-1)
#define fn(i,x) for(i=0;i<x;i++)
#define fs(i,s,x) for(i=s;i<x;i++)
#define fr(i,x,s) for(i=x;i>=s;i--)
#define fit(itr,s) for(itr=s.begin();itr!=s.end();itr++)
#define W while
#define pp pair<ll,ll>
#define ppi pair<int,int>
#define vl vector<ll>
#define vll vector<pp >
#define vi vector<int>
#define vii vector<ppi>
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(x,y,z,w) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\t"<<#w<<" :: "<<w<<endl;
#define boost  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const int MAX=2e5+5;
const ll MM=1e16;
const ll mod=998244353;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
//insert a element in vector at position i  vec.insert(vec.begin()+i,element)
//atmost 1e5 insertion allowed in 1 sec

ll expo(ll x,ll n,ll M=mod)
{
    ll ans=1;
    while(n>0)
    {
        if(n&1){ans=(ans*x)%M;}
                x=(x*x)%M;
                n>>=1;
    }
    return ans;
}

void solve()
{
    ll n,m,i,j,k,ans=0;
    cin>>n;
    vl v(n);
    fn(i,n)cin>>v[i];
    fn(i,n)
    {
        ll temp=v[i],cnt=0;
        W(i<n && temp>=v[i]){
            temp=v[i];
            i++;cnt++;
        }
        i--;
        
        ans=max(ans,cnt);
    }
    cout<<ans-1<<endl;
    
}

int main()
{
  boost;
  ll t=1;
//   cin>>t;
  while(t--)
  {
      solve();
  }
}
