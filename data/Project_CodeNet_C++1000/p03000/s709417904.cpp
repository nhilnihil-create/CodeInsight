#include <bits/stdc++.h>
typedef long long ll;
#define fr(i,a,b) for(ll i=a; i<b; i++)
#define rf(i,a,b) for(ll i=a; i>=b; i--)
typedef std::vector<long long > vi ;
#define F first
#define S second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define PB push_back
#define MP make_pair
#define PI 3.14159265358979323846
#define all(a) a.begin(),a.end()
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
#define endl '\n'
#define show(a) for(auto el:a)cout<<el<<" "
const ll INF=LLONG_MAX/2;
const ll N=2e5+1;
#define yesno(f) yes(f);no(f);
#define yes(f) if(f)cout<<"YES\n";
#define no(f) if(!f)cout<<"NO\n";
using  namespace std;
int main()
{
    fast;
   ll t=1;
   //std::cin >> t;
   while(t--)
   {
       ll n,i,j=0,x,b;
       std::cin >> n>>x;
       ll a[n+1],d[n+2]={0};
       fr(i,1,n+1)
       std::cin >> a[i];
       fr(i,2,n+2)
       {
           d[i]=d[i-1]+a[i-1];
           if(d[i]>x)
           {
               j=1;
               cout<<i-1<<"\n";
               break;
           }
       }
       if(j==0)
       cout<<n+1<<"\n";
   }
}