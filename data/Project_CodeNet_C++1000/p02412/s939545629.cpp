// 1_7_B
#include <iostream>
using namespace std;

int main(){
  int n, x, count, i, j;
  while(true){
    cin >> n >> x;
    if(n == 0 && x == 0) return 0;
    count = 0;
    for(i = 1; i < n; i++){
      for(j = i+1; j < n; j++){
        if(x-i-j > j && x-i-j <= n) count++;
      }
    }
    cout << count << endl;
  }
}