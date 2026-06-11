#include <iostream>
#include <vector>
using namespace std;

int func(int n, int s, int sum = 0, int mx = -1){
  if(n == 0){
    return (s == sum) ? 1 : 0;
  }

  int ans = 0;
  for(int i = mx + 1; i <= 9; i++){
    ans += func(n - 1, s, sum + i, i);
  }
  return ans;
}


int main(void){
  while(true){
    int n, s;
    cin >> n >> s;
    if(n == 0 && s == 0){ break; }
    cout << func(n, s) << endl;
  }
  
  return 0;
}

