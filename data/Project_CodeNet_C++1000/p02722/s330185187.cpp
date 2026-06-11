#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll k;
  cin >> k;
  ll count=2;
  
  if(k==2){
    cout << 1 << endl;
    return 0;
  }
  
  for(int i=2; i<=pow(k,0.5); i++){
    ll K=k;
    if(K%i==0){
      while(K%i==0){
        K/=i;
      }
      if(K==1) count++;
      else if(K%i!=0 && (K-1)%i==0) count++;
    }
    
    else if(K%i!=0 && (K-1)%i==0){
      if((K-1)/i==i)count++;
      else count+=2;
    }
  }
  
  cout << count << endl;
  
}
