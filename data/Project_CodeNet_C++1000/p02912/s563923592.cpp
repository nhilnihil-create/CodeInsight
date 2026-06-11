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
  ll n,m;cin>>n>>m;
  ll a;
  priority_queue<ll> q;
  rep(i,n){
    cin>>a;
    q.push(a);
  }
  
  rep(i,m){
    ll now=q.top();
    q.pop();
    now/=2;
    q.push(now);
  }
  ll ans=0;
  
  
  rep(i,n){
    ll now=q.top();
    q.pop();
    ans+=now;
  }
  
  cout<<ans<<endl;
}
