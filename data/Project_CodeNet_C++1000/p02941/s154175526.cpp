 #include <bits/stdc++.h>
 #define ll long long
#define int long long
 #define MOD  1000000007
 #define MAX 500005
 #include<iomanip>
 #define fast ios_base :: sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
 #define test int t; cin >> t; while(t--)
 #define inp(n) int n;cin >> n;
 #define mp make_pair
 #define pb push_back
 #define forl(i,a,b) for(ll i=a;i<b;i++)
 #define x first
 #define y second

using namespace std;
ll gcd(ll a, ll b)
{
    if (b == 0)   return a;  return gcd(b, a % b);
}

 int32_t main()
{
     fast;
    
//    test
//    {
//       
//    }
    ll n;
    cin>>n;ll ans=0;
    ll arr[200005],brr[200005];
    for(ll i=0;i<n;i++)cin>>arr[i]; for(ll j=0;j<n;j++)cin>>brr[j];
    priority_queue < pair < ll, ll> > pq;
    for(ll i=0;i<n;i++)
    {
        if(brr[i]>=arr[i])
        pq.push( mp(brr[i],i) );// check for -1 ..//
        else return cout<<"-1"<<endl,0;
    }
    int pre=-1;
    while(!pq.empty())
    {
        ll val,ind;
        auto it=pq.top();
        pq.pop();
        val=it.x;ind=it.y;
        if(pre==ind) {return cout<<"-1",0;}else pre = ind;
    
        brr[ind] = arr[ind]+(val-arr[ind])%(brr[(ind-1+n)%n]+brr[(ind+1)%n]);
        ans+=(val-arr[ind])/(brr[(ind-1+n)%n]+brr[(ind+1)%n]);
        if(brr[ind]<arr[ind]){return cout<<"-1",0;}
        if(brr[ind]>arr[ind])
        {
            pq.push(mp(brr[ind],ind));
        }
        
    }
    cout<<ans<<endl;
    return 0;
 }
  












