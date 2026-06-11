#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll a;
  double b,c;
  cin>>a>>b;
  c=0;
  vector<ll>vec(a);
  for(ll i=0;i<a;i++){
    cin>>vec.at(i);
    c+=vec.at(i);
  }
  double g;
  g=c/4/b;
  sort(vec.begin(),vec.end());
  if(vec.at(a-b)>=g){
    cout<<"Yes"<<endl;
    return 0;
  }
  cout<<"No"<<endl;
}
