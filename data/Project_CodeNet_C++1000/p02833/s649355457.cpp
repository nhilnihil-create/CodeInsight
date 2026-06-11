#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin>>n;
  if(n%2) cout<<0;
  else{
    long long ret = 0;
    while(n){
      ret+=n/10;
      n/=5;
    }
    cout<<ret;
  }
}