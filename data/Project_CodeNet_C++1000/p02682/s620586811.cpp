#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll=long long;

int main(){
  ll A, B, C, K;
  int max=0;
   cin >> A >> B >> C >> K;
  
  rep(i,K){
    if(i<A) max += 1;
    if(A<=i&&i<A+B) max=max;
    if(A+B<=i&&i<=A+B+C) max-= 1;
    
  }
   cout << max << endl;
   return 0;
  
}
  
  
