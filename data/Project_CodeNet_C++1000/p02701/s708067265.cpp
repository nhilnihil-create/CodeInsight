#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  vector<string>vec(a);
  for(ll i=0;i<a;i++){
    cin>>vec.at(i);
  }
  sort(vec.begin(),vec.end());
  ll b=1;
  if(a>1){
    for(ll i=0;i<a-1;i++){
      if(vec.at(i)!=vec.at(i+1)){
        b+=1;
      }
    }
  }
  cout<<b<<endl;
}
