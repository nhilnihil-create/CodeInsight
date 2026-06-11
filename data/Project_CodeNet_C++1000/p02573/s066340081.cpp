#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define  boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define d1(x) cout<<#x<<" "<<x<<endl;
#define d2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define d2i(x,y,i) cout<<#x<<i<<" "<<x<<" "<<#y<<i<<" "<<y<<endl;
#define all(v) v.begin(),v.end()
#define fr(i,l,r) for(ll i=l;i<r;i++)
#define mems(a,x) memset(a,x,szeof(a))
#define pp pair<ll,ll>
#define mod 1000000007
#define ff first
#define ss second
#define pb(x) push_back(x)
#define vll vector<ll>
#define pbp(x,y) push_back(make_pair(x,y))
#define  ma0t vector<vector<ll>>
#define el cout<<'\n';
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const int N=2*(1e5)+10;
int sze[N];
int par[N];
void ini(){
  for(int i=0;i<N;i++)
  sze[i]=1,par[i]=i;
}
int parent(int x){
  if(par[x]==x)
  return x;
  return par[x]=parent(par[x]);
}
void uni(int x,int y){
  x=parent(x);
  y=parent(y);
  if(x==y)
  return ;
  if(sze[x]<sze[y])
  swap(x,y);
  par[y]=x;
  sze[x]+=sze[y];
  sze[y]=0;
}
void solve(){
  ll n,m;
  cin>>n>>m;
  ini();
  ll u,vv;
  fr(i,0,m){
    cin>>u>>vv;
    uni(u,vv);
  }
vll v(n);
fr(i,1,n+1){
  v[i-1]=sze[i];
}
sort(all(v));
ll ans=0;
ll curr=0;
for(int i=0;i<n;i++){  
  //d1(v[i]);
  if(curr+v[i]>(ll)0){
   
  
    ans+=curr+v[i];
  
    curr-=curr+v[i];
  }

}
cout<<ans;


}
int main()
{
    ll t=1;
  //  cin>>t;
    while(t--)
    {
     solve();
     cout<<endl;
    }
	return 0;
}