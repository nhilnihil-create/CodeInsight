#include<bits/stdc++.h>
using namespace std;
 
int main(){
  long long a;
  cin >> a;
  int ans = 0;
  long long p = 100;
  for(int i = 0; ; i++){
    p += p / 100;
    if (p >= a) { ans = i + 1; break; }
  }
  cout << ans << endl;
}