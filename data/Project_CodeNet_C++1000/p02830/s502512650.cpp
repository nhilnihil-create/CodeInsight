#include <bits/stdc++.h>
using namespace std;
using ll =long long ;
int main() {
  ll a;
  cin>>a;
  vector<char>vec(a);
  vector<char>veco(a);
  for(ll i=0;i<a;i++){
    cin>>vec.at(i);
  }
  for(ll i=0;i<a;i++){
    cin>>veco.at(i);
  }
  for(ll i=0;i<a;i++){
    cout<<vec.at(i)<<veco.at(i);
  }
  cout<<endl;
  return 0;
}
  