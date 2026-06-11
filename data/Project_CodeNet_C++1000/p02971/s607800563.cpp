#include <iostream>

using namespace std;

int main() {

  int n, max1 = 0, max2 = 0, pos = 0, k;
  cin >> n;
  for(int i = 1;i <= n;i++){
    cin >> k;
    if(max1 <= k){
      pos = i;
      max2 = max1;
      max1 = k;
    }else if(max2 < k){
      max2 = k;
    }

  }
  for(int i = 1;i <= n;i++){
    //cin >> k;
    if(pos == i){
      cout << max2 << '\n';
    }else{
      cout << max1 << '\n';
    }

  }
  return 0;
}
