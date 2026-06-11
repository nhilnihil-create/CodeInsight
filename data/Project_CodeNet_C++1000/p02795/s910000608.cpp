#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int h,w,n;
  cin >> h >> w >> n;
 
  int s=max(h,w);
  
  if(n%s==0){
    cout << n/s << endl;
  }
  else if(n%s!=0){
    cout << n/s + 1 << endl;
  }
}
