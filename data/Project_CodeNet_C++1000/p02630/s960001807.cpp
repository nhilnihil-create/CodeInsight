#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define ff first
#define ss second
#define vi vector<ll>
#define mod 1000000007
#define MOD 1000000007
#define full(a) a.begin(),a.end()
#define inf INT_MAX
#define minf INT_MIN
#define dd double
#define fori(x,n) for(ll i=x;i<n;i++)
#define modd 998244353
#define umap unordered_map<ll,ll>
#define mmap map<ll,ll>

int32_t main() 
{ 
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    
 
       ll n;
       cin>>n;
       ll sum=0;
       ll cnt[100005]={0};
       fori(0,n){
        ll x;
        cin>>x;
        cnt[x]++;
        sum+=x;
       }
       ll q;
       cin>>q;
       while(q--){
        ll x,y;
        cin>>x>>y;
        sum =sum - cnt[x]*(x-y);
        cout<<sum<<"\n";
        cnt[y]+=cnt[x];
        cnt[x]=0;
       }
      
 

     
 
return 0;
}     