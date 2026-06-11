#include<bits/stdc++.h>
using namespace std;
#define MAX 123456

vector< bool > prime( MAX*2+1, true);

void get_prime(int n){
  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;
  
  for(int i = 2; i * i <= n; i++){
    if(prime[i]){
      for(int j = i + i; j <= n; j += i) prime[j] = false;
    }
  }
}

int main(){
  get_prime(MAX*2+1);
  int n;
  while(cin >> n , n){
    int ans = 0;
    for(int i=n+1;i<=2*n;i++){
      if(prime[i]) ans++;
    }
    cout << ans << endl;
  }
}