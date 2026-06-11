#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int n,a,b;
  cin>>n>>a>>b;
  if(n%(a+b)<=a){
    cout<<n/(a+b)*a+n%(a+b)<<endl;
  }
  else{
    cout<<n/(a+b)*a+a<<endl;
  }
}