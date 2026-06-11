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

ll t[4*MAXN];
ll tadd[4*MAXN];

void build(ll v,ll l,ll r)
{
  if(l==r)
  {
	t[v]=massiv[l-1].second;
	return ;  
  }	
  ll mid=l+(r-l)/2;
  build(v*2,l,mid);
  build(v*2+1,mid+1,r);
  t[v]=min(t[v*2],t[v*2+1]);
}

void push(ll v,ll l,ll r)
{
  if(tadd[v]!=0)
  {
   t[v]+=tadd[v];
   if(l!=r)
   {
	 tadd[v*2]+=tadd[v];
	 tadd[v*2+1]+=tadd[v];   
   }
   tadd[v]=0;
  }
	
}

void update(ll v,ll l,ll r,ll nac,ll konec,ll x)
{
  push(v,l,r);
  if(l>konec || r<nac)return ;
  if(l>=nac && r<=konec)
  {
	tadd[v]+=x;
	push(v,l,r);
	return ;
  }	
  ll mid=l+(r-l)/2;
  update(v*2,l,mid,nac,konec,x);
  update(v*2+1,mid+1,r,nac,konec,x);
  t[v]=min(t[v*2],t[v*2+1]);
}


ll query(ll v,ll l,ll r,ll nac,ll konec)
{
  push(v,l,r);
  if(l>konec || r<nac)return LLONG_MAX;
  if(l>=nac && r<=konec)return t[v];
  ll mid=l+(r-l)/2;
  ll one=query(v*2,l,mid,nac,konec);
  ll two=query(v*2+1,mid+1,r,nac,konec);
  return min(one,two);	
}

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
build(1,1,n);
ll ans=0;
for(ll i=0;i<n;i++)
{
  ll xp=query(1,1,n,i+1,i+1);
  ll nac=i;
  ll konec=n-1;
  ll maxx=0;
  if(xp<=0)continue;
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
  update(1,1,n,i+1,maxx+1,-(a*kol));
  
}


cout<<ans<<endl;


return 0;
} 
