


#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


const int MAXN = 1005;

int main() {
  int n,k;
  cin>>n>>k;
  vector<int>a(n);
  rep(i,n)cin>>a[i];
  set<ll>G;
  ll sum=0;
  rep(i,n)sum+=a[i];
  //cout<<sum;
  for(int i=1;i*i<=sum;i++){
    if (sum%i==0){
      G.insert(i);
      G.insert(sum/i);
    }
  }
ll ans=1;
  for(ll x:G){
  //  cout<<x<<'x'<<endl;
    vector<ll> r(n);
    rep(i,n)r[i]=a[i]%x;
    sort(r.begin(),r.end());
    ll cnt1=0;
    ll cnt2=0;

    rep(i,n)cnt1+=x-r[i];
    ll need=1e18;
    rep(i,n){
      cnt1-=x-r[i];
      cnt2+=r[i];

      need=min(need,max(cnt1,cnt2));
    //  cout<<cnt1<<'1'<<cnt2<<'2'<<endl;
        }
    if (need<=k) ans=max(ans,x);
  }
cout<<ans;
}
