#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin >> n;
  
  long long ans = 0, div = 10;
  while(div <= n){
    ans += n / div;
    div *= 5;
  }
  if(n %2) ans = 0;
  
  cout << ans << endl;
}