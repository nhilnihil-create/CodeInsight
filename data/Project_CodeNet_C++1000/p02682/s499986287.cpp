#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int a,b,c,k;
  cin>>a>>b>>c>>k;
  if(a>=k){
    cout<<k<<endl;
  }
  else if(a<k){
    if(a+b>=k){
      cout<<a<<endl;
    }
    else if(a+b<k){
      if(a+b+c>=k){
        cout<<a*2+b-k<<endl;
      }
    }
  }
}