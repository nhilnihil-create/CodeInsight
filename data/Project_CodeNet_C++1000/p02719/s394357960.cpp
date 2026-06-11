#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t x, K;
  cin>>x>>K;
  int64_t t=0;
  if(x>K){
    t=x%K;
    if(t<K-t){
      cout<<t<<endl;
    }
    else{
      cout<<K-t<<endl;
    }
  }
  else{
    t=x;
    if(t<K-t){
      cout<<t<<endl;
    }
    else{
      cout<<K-t<<endl;
    }
  }
    
}
  