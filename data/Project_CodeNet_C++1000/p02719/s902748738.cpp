#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int n,k;
  cin>>n>>k;
  if(n%k==0){
    cout<<"0"<<endl;
  }
  else{
    if(n%k*2<k){
      cout<<n%k<<endl;
    }
    else{
      cout<<k-n%k<<endl;
    }
  }
}