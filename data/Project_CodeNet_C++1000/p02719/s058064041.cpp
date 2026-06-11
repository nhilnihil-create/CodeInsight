#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n,k;	cin >> n >> k;
  if(n/k>0){
      n-=n/k*k;
    }
  while(1){
    if(n>abs(n-k)){
      n=abs(n-k);
    }else{
      cout << n;
      return 0;
    }
  } 
}