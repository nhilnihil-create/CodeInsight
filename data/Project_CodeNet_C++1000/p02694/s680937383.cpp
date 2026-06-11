#include<bits/stdc++.h>
using namespace std;
int main(){
  long long int x;
  cin >> x;
  long long int m = 100;
  int ans = 0;
  while (m < x){
    m += m/100;
    ans++;
  }
  cout << ans << endl;
}
