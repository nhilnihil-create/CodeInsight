#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main(void){
  int m,d;
  cin >> m >> d;
  int ans = 0;
  for(int i = 1;i <= m;i++){
        for(int j = 1;j <= d;j++){
              int a = j % 100 / 10;
              int b = j % 10;
              if(a >= 2 && b >= 2){
                    if(a * b == i){
                          ans++;
                    }
              }
        }
  }
  cout << ans << endl;
}
