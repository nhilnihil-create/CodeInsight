#include<bits/stdc++.h>
using namespace std ; 


int main() {
  long long N , K ; 
  cin >> N >> K ; 
  
  if( N % K <= K - (N%K)){
    cout << N%K << endl ; 
  }

  else  {
    cout << K-(N%K) << endl ; 
    
  }

  
}