#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll b,a;
  cin>>b>>a;
  vector<ll>vec(a);
  ll c=0;
  for(ll i=0;i<a;i++){
    cin>>vec.at(i);
    c+=vec.at(i);
  }
  if(b>c){
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;
}