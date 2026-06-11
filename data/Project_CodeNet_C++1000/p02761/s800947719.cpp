#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  int a;
  cin>>a;
  vector<ll>vec(a,0);
  vec.at(0)=1;
  vec.at(a-1)=0;
  vector<ll>veco(a);
  int b;
  cin>>b;
  for(ll i=0;i<b;i++){
    ll c;
    cin>>c;
    ll d;
    cin>>d;
    if(veco.at(c-1)==0){
      veco.at(c-1)+=1;
      vec.at(c-1)=d;
    }
    else{
      if(vec.at(c-1)!=d){
        cout<<-1<<endl;
        return 0;
      }
    }
  }
  if(vec.at(0)==0&&a>1){
    cout<<-1<<endl;
    return 0;
  }
  for(ll i=0;i<a;i++){
    cout<<vec.at(i);
  }
  return 0;
}
      
    

