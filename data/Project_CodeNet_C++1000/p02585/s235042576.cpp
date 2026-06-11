#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,s,n) for(int i=s;i<n;i++)
#define per(i,s,n) for(int i=n-1;i>=s;i--)
#define fi first
#define se second
#define all(c) c.begin(),c.end()
typedef long long int ll;
typedef pair<int, int> P;
typedef long double ld;
void Ans(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}

const ll INF=1001001001;
const ll mod=1000000007;

int main(){
  ll n,k;
  cin>>n>>k;
  ll p[n];
  ll c[n];
  ll ans=-INF;
  rep(i,n){
    cin>>p[i];
    p[i]--;
  }
  rep(i,n){
    cin>>c[i];
  }
  
  rep(i,n){
    ll nc=0;
    ll v=i;
    ll cnt=0;
    
    
    while(true){
      nc+=c[v];
      cnt++;
      v=p[v];
      if(v==i) break;
    }
    
    ll count=0;
    ll now=0;
    
    while(true){
      now+=c[v];
      count++;
      
      if(count>k) break;
      
      ll s=now+max(0ll,nc)*((k-count)/cnt);
      ans=max(ans,s);
      
      v=p[v];
      if(v==i) break;
    }
    
  }
  
  cout<<ans<<endl;
}
      

