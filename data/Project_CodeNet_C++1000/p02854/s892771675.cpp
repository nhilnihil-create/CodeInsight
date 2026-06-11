#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll sum=0;
  rep(i,n){
    cin >> a.at(i);
    sum+=a.at(i);
  }
  ll p=0,ans=1e10;
  rep(i,n){
    sum-=a.at(i);
    p+=a.at(i);
    ans=min(ans,abs(p-sum));
  }
  cout << ans;
}
  