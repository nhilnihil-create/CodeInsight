#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  vector<pair<ll,ll>> a(n);
  rep(i,n){
    ll c,b;
    cin >> c >> b;
    a.at(i)=make_pair(b,c);
  }
  string s="Yes";
  ll p=0;
  sort(a.begin(),a.end());
  rep(i,n){
    p+=a.at(i).second;
    if(p>a.at(i).first){
      s="No";
    }
  }
  cout << s;
}
    