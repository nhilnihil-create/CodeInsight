#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 vector<ll> vec(3);
  for(ll i=0;i<3;i++) {
cin>>vec[i];
  }
  sort(all(vec));
  cout<<vec[0]+vec[1]<<endl;
}
