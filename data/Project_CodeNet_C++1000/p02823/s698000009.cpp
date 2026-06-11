#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n, a, b;
  cin >> n >> a >> b;
  
  long long ans = (b-a) / 2;
  if((b-a)%2 == 1){
    ans = (n-b) + (b-a+1) / 2;
    ans = min(ans, (a-1) + (b-a+1) / 2);
  }
  
  cout << ans << endl;
}