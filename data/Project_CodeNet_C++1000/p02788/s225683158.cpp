#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
typedef pair<ll,ll> P;

int main() {
  int n,d,a;
  cin>>n>>d>>a;
  vector<vector<ll>> x(n,vector<ll>(2));
  rep(i,n) {
    rep(j,2){
      cin >> x.at(i).at(j);
    }
  }
  sort(x.begin(),x.end());
  vector<ll>y(n),z(n);
  rep(i,n){
    y.at(i)=x.at(i).at(0);
    z.at(i)=x.at(i).at(1);
  }
  ll ans=0;
  ll co=0;
  queue<P>q;
  rep(i,n){
    while(q.size()&&q.front().first<y.at(i)){
      co-=q.front().second;
      q.pop();
    }
    z.at(i)-=co;
    if(z.at(i)>0){
      ans+=(z.at(i)+a-1)/a;
      co+=((z.at(i)+a-1)/a)*a;
      q.push(P(y.at(i)+2*d,((z.at(i)+a-1)/a)*a));
    }
  }  
  cout<<ans<<endl;  
}