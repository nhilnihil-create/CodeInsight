#include <bits/stdc++.h>
using namespace std;
int a[110];
int ans1, ans2;
int main(){
  int x, y;
  cin >> x >> y;
  if(y == 0)
  {
    cout << x;
    return 0;
  }
  for(int i = 0;i < y;i++)
  {
    cin >> a[i];
  }
  sort(a, a + y);
  for(int i = 0;i != -1;i++){
    if(binary_search(a, a+y, x + i) == false){
      ans1 = x + i;
      break;
    }
  }
  for(int i = 0;i != -1;i++){
    if(binary_search(a, a+y, x - i) == false){
      ans2 = x - i;
      break;
    }
  }
  if(fabs(ans2 - x) <= fabs(ans1 - x)){
    cout << ans2;
    return 0;
  }
  cout << ans1;
  return 0;
}