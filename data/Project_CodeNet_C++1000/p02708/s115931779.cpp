#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
 
using namespace std;


int main(){
  long long N,K;
  cin >> N >> K;
  long long ans = 0;
  for(int i = K; i<= N+1; i++){
    ans += (i*(N-i+1) + 1);
    ans %= 1000000007;
  }
  
  cout << ans << endl;
  
}

