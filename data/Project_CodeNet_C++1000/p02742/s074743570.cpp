#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int h,w;
  cin >> h >> w;
  int odd = (w+1)/2;
  int even = w/2;
  int oddCount = (h+1)/2;
  int evenCount = h/2;
  
  if(h == 1 || w == 1){
	cout << 1 << endl;
  }else{
     cout << (ll)odd*oddCount + (ll)even*(evenCount) << endl;
  }
  
 
  
  return 0;
}