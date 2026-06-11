#include <bits/stdc++.h>
using namespace std;

int main(){
  long long a,b,k;
  cin>>a>>b>>k;
  if(a>=k){
    cout<<a-k<<" "<<b<<endl;
    return 0;
  }
  if(a+b>=k){
    cout<<0<<" "<<a+b-k<<endl;
    return 0;
  }
  cout<<0<<" "<<0<<endl;
  return 0;
}
