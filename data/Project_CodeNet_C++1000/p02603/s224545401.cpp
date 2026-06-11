
#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1e18;

P f(ll n,ll c){
  ll s=n/c;
  ll q=n-(s*c);
  P ans=make_pair(s,q);
//  cout<<"n"<<n<<"s"<<s<<"q"<<q<<endl;
  return ans;

  }


int main() {
  ll n;
  cin>>n;
  vector<ll> a(n);
  rep(i,n)cin>>a[i];
  ll cost=a[0];
  ll kabu=0;
  ll money=1000;
  rep(i,n-1){
    if (a[i+1]>cost){
      P temp=f(money,cost);
      kabu+=temp.first;
      money=temp.second;
      ll now=kabu*a[i+1];
      kabu=0;
      money+=now;
    }

    else if (a[i+1]<cost){
      ll now=kabu*cost;
      kabu=0;
      money+=now;
      P temp=f(money,a[i+1]);
      kabu+=temp.first;
      money=temp.second;

  }
  cost=a[i+1];
//  cout<<money<<" "<<kabu<<endl;
}

ll ans=money+(kabu*cost);
cout<<ans;
}
