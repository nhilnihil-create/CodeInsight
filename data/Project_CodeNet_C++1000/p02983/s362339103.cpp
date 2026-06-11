#include <bits/stdc++.h>
using namespace std;

int main(){
  int l, r, min=2018;
  cin >> l >> r;
  
  for(int i=l; i <= r-1; i++){
    for(int j=r; j >= l+1; j--){
      if(min == 0) break;
      int left=i, right=j;
      left %= 2019;
      right %= 2019;
      if(left*right%2019 < min) min = left*right%2019;
    }
  if(min == 0) break;
  }
  cout << min << endl;
}
