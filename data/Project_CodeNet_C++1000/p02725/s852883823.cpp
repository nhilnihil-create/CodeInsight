#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll a,b;
  cin>>a>>b;
  vector<ll>vec(b);
  for(ll i=0;i<b;i++){
    cin>>vec.at(i);
  }
  sort(vec.begin(),vec.end());
  vector<ll>re(b);
  for(ll i=0;i<b-1;i++){
    re.at(i)=vec.at(i+1)-vec.at(i);
  }
  re.at(b-1)=vec.at(0)+a-vec.at(b-1);
  sort(re.begin(),re.end());
  cout<<a-re.at(b-1)<<endl;
  
}
