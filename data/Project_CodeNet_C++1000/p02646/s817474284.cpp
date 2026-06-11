#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
int main(){
  ll a,v;cin>>a>>v;
  ll b,w;cin>>b>>w;
  ll t;cin>>t;
  if(v<=w){
    cout<<"NO"<<endl;
    return 0;
  }
  if(abs(b-a)>t*(v-w)){
    cout<<"NO"<<endl;
    return 0;
  }
  cout<<"YES"<<endl;
  return 0;
}
  