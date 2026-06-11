#include <bits/stdc++.h>
using namespace std;
int main(){
  long long a,v,b,w,t;
  cin>>a>>v>>b>>w>>t;
  if(v<=w){
    cout<<"NO"<<endl;
    return 0;
  }else{
    long long kyori0=b-a;
    long long kyori1=v-w;
    if(abs(kyori0)<=t*kyori1){
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }
  }
  return 0;
}
