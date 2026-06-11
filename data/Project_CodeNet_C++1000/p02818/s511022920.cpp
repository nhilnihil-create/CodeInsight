#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a,b,k,x; cin>>a>>b>>k;
  if(a<k){
    k-=a;
  }else{
    cout<<a-k<<" "<<b<<endl;
    exit(0);
  }
  if(b<k){
    cout<<"0 0"<<endl;
  }else{
    cout<<"0 "<<b-k<<endl;
  }
}