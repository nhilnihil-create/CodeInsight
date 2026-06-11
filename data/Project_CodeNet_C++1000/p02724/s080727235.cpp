#include<bits/stdc++.h>
using namespace std;

int main(){
  long long x, ans = 0;
  cin >> x;
  ans += (x/500)*1000;
  x-=ans/2;
  ans+=(x/5)*5;
  cout << ans << endl;
  
}
