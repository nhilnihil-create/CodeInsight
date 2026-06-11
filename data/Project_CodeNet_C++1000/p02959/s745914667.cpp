#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n+1),b(n);
  rep(i,n+1){
    cin >> a.at(i);
  }
  rep(i,n){
    cin >> b.at(i);
  }
  ll ans=0,q=0;
  rep(i,n){
    if(a.at(i)+a.at(i+1)<=b.at(i)){
      ans+=a.at(i)+a.at(i+1);
      a.at(i)=0;
      a.at(i+1)=0;
    }else if(a.at(i)<=b.at(i)){
      ans+=b.at(i);
      a.at(i+1)-=b.at(i)-a.at(i);
      a.at(i)=0;
    }else{
      ans+=b.at(i);
    }
  }
  cout << ans;
}
    