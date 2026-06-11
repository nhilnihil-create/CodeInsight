#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n,k;
  cin >> n >> k;
  long long ans=0;
  while(k<=n+1){
    ans=(ans+(k*(n-k+1)+1))%1000000007;
    k++;
  }
  cout << ans << endl;
  return 0;
}  
