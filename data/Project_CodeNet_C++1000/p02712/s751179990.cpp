#include<bits/stdc++.h>
using namespace std;
int main(){
  long long  a,j=0;
  cin>>a;
  for(long long i=1;i<=a;i++){
    if(i%3 == 0 || i%5 == 0){
      continue;
    }
    else{
      j+=i;
    }
  }
  cout<<j<<'\n';
}
