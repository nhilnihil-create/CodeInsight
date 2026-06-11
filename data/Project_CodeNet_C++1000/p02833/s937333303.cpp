#include<bits/stdc++.h>
using namespace std;
int main(void){
  long long n; cin>>n;
  long long res=0;
  if((n&1)==0){
    long long five=5,i;
    while(i=n/five/2) res+=i,five*=5;
  }
  cout<<res;
  return 0;
}
