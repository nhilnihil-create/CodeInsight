#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t h,k;
  cin >> h >> k;
  if(h==1 || k==1)cout << 1 << endl;
  else {
    if(h%2==0 || k%2==0)cout << (int64_t)(h*k)/2 << endl;
    else cout << (int64_t)(h*k)/2+1 << endl;
  }
}
