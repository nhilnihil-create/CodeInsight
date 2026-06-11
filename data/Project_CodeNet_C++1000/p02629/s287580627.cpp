#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n;
  cin>>n;
  string ans="";
  while(n){
    long long k=n/26;
    long long z=n%26;
    if(z==0){
      k--;
      ans=(char)('z')+ans;
    }
    else ans=(char)('a'+z-1)+ans;
    n=k;
  }
  cout<<ans;
  return 0;
}