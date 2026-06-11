#include <bits/stdc++.h>
#define FLASH ios_base::sync_with_stdio(0);
#define ll long long
#define debt(x,y)cout<<"#x = "<<(x)<<" and "<<"#y = "<<(y)<<endl;
#define deb(x)cout<<"#x = "<<(x)<<endl;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define arr(a,n) for(ll i=1;i<=n;i++) cout<<a[i]<<" "; cout << "\n";
#define vecc(a,n) for(ll i=0;i<n;i++) cout<<a[i]<<" "; cout << "\n";
#define MAXN 200010

using namespace std;

ll n,d,a;
vector<pair<ll,ll> >massiv;

ll lazy[MAXN];

int main(){
FLASH;
cin>>n>>d>>a;
for(ll i=1;i<=n;i++)
{
 ll x,y;
 cin>>x>>y;
 massiv.pb(mp(x,y));
}
sort(all(massiv));

ll ans=0;
for(ll i=0;i<n;i++)
{
  ll xp=massiv[i].second-lazy[i];
  ll nac=i;
  ll konec=n-1;
  ll maxx=0;
  if(xp>0)
  {
   while(nac<=konec)
   {
    ll mid=nac+(konec-nac)/2;
    if(massiv[mid].first-massiv[i].first<=2*d)
    {
	  maxx=max(maxx,mid);
	  nac=mid+1;	
    }  
    else konec=mid-1;
   }	
   ll kol;
   if(xp%a==0)kol=xp/a;
   else kol=xp/a+1;
   ans+=kol;
   lazy[i]+=a*kol;
   lazy[maxx+1]-=a*kol;
  }
  lazy[i+1]+=lazy[i];
}


cout<<ans<<endl;


return 0;
} 
