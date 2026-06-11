#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<ll> a(3);
  rep(i,s.size()){
    if(s.at(i)=='R'){
      a.at(0)++;
    }
    if(s.at(i)=='G'){
      a.at(1)++;
    }
    if(s.at(i)=='B'){
      a.at(2)++;
    }
  }
  ll ans=a.at(0)*a.at(1)*a.at(2);
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(2*j-i<n && s.at(i)!=s.at(j) && s.at(i)!=s.at(2*j-i) && s.at(j)!=s.at(2*j-i)){
        ans--;
      }
    }
  }  
  cout << ans;
}
