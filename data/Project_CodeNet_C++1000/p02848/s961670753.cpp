#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  string c;
  cin>>c;
  vector<char>vec(c.size());
  for(int i=0;i<c.size();i++){
    vec.at(i)=c.at(i);
  }
  if(a>0){
  for(int i=0;i<vec.size();i++){
    for(ll j=0;j<a;j++){
      if(vec.at(i)=='Z')vec.at(i)='A';
    else vec.at(i)+=1;
    }
  }
  }
  
  for(int i=0;i<vec.size();i++){
    cout<<vec.at(i);
  }
  return 0;
}
     
