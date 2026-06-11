#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,n,a;
  cin >> x >> n;
  vector<int> p(n);
  vector<int> arr(101, 1);
  for(int i=0; i<n; i++){
    cin >> a;
    arr.at(a) = 0;
  }
  int j=1, check = 1;
  if(arr.at(x)==1){
    cout << x << endl;
    return 0;
  }
  while(check==1){
    if(x+j > 100){
      int ans = x+j;
      if(arr.at(x-j)==1){
        ans = x-j;
      }
      cout << ans << endl;
      return 0;
    }
    if(x-j < 1){
      int ans = x-j;
      if(arr.at(x+j)==1){
        ans = min(x-j,x+j);
      }
      cout << ans << endl;
      return 0;
    }
    if(x-j < 1){
      int ans = min(abs(x+j), abs(x-j));
      cout << ans << endl;
      return 0;
    }
    if(arr.at(x-j)==1){
      cout << x-j << endl;
      return 0;
    }
    else if(arr.at(x+j)==1){
      cout << x+j << endl;
      return 0;
    }
    j++;
  }
}