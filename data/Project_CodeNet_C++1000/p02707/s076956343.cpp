#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  vector<ll>vec(a,0);
  for(ll i=0;i<a-1;i++){
    ll b;
    cin>>b;
    vec.at(b-1)+=1;
  }
  for(ll i=0;i<a;i++){
    cout<<vec.at(i)<<endl;
  }
}    