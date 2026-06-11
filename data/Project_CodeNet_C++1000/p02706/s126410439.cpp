#include <bits/stdc++.h>
using namespace std;
using ll=long long; 
int main(){
  ll m;
  cin>>m;
  ll N;
  ll c=0;
  cin>>N;
  vector<ll>tr(N);
  for(ll i=0;i<N;i++){
    cin>>tr.at(i);
    c+=tr.at(i);
  }
  ll b=m-c;
  if(b<0){
    b=-1;
  }
  cout<<b<<endl;
  
    
  
}
