#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n;
  int k;	
  cin >> n >> k;
  int ans=0;
  while(1){
    n/=k;
    ans++;
    if(n==0){
      cout << ans;
      return 0;
    }
  }
}