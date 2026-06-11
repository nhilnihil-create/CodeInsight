#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll A,B,C,D,e,f;
  cin>>A>>B>>C>>D;
  e=A/D;
  f=C/B;
  if(A%D!=0){
    e+=1;
  }
  if(C%B!=0){
    f+=1;
  }
  if(f>e){
    cout<<"No"<<endl;
  }
  else{
    cout<<"Yes"<<endl;
  }
  
  
  
}
