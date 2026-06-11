#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define  boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define d1(x) cout<<#x<<" "<<x<<endl;
#define d2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define d2i(x,y,i) cout<<#x<<i<<" "<<x<<" "<<#y<<i<<" "<<y<<endl;

#define fr(i,l,r) for(ll i=l;i<r;i++)
#define mems(a,x) memset(a,x,sizeof(a))
#define mod 1000000007
#define ff first
#define ss second
#define pb(x) push_back(x)
#define vll vector<ll>
#define pbp(x,y) push_back(make_pair(x,y))
#define  mat vector<vector<ll>>
#define all(v) v.begin(),v.end()
#define pm(v,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<v[i][j]<<" ";cout<<endl;}
///////////////////////////////////////////
/// choose such no such that every 5 sum of nu mber is divisible by 5

void solve(){
  ll n,m;
  cin>>n>>m;
  vll a(n),b(m);
  mat v(n+1,vll(m+1));
  mat sm(n+1,vll(m+1));
  for(ll &x:a)
  cin>>x;
  for(ll &x:b)
  cin>>x;
  v[0][0]=1;
  fr(i,0,m+1)
  sm[0][i]=1;
  fr(i,0,n+1)
  sm[i][0]=1;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){

      if(a[i]==b[j]){
        v[i+1][j+1]=sm[i][j];
      }
      else v[i+1][j+1]=0;
      sm[i+1][j+1]=(sm[i+1][j]+sm[i][j+1]-sm[i][j]+mod)%mod;
      sm[i+1][j+1]=(sm[i+1][j+1]+v[i+1][j+1])%mod;
    }
  }
  //pm(v,n+1,m+1);
  //pm(sm,n+1,m+1);
  
 //if(a[n-1]==b[m-1])
 //cout<<v[n][m];
  cout<<sm[n][m]%mod;
}




int main(){
    ll t=1;
  //cin>>t;
    while(t--){
        solve();
        cout<<endl;
    
    }
    return 0;
}