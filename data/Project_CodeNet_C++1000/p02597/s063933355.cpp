#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph = vector<vector<ll>>;
int main(){
  ll A;
  cin>>A;
  vector<ll>vec(0);
  for(ll i=0;i<A;i++){
    char a;
    cin>>a;
    if(a=='R'){
      vec.push_back(i+1);
    }
  }
  sort(vec.begin(),vec.end());
  ll f=vec.size();
  ll g=0;
  for(ll i=0;i<f;i++){
    if(vec.at(i)>vec.size()){
      g=i;
      break;
    }
    if(i==f-1){
      g=f;
    }
  }
  cout<<min(f-g,A-f)<<endl;
    
}
    
