#include<bits/stdc++.h>
using namespace std;

int main(){
  int m,d;
  cin >> m >> d;
  int ans = 0;
  for(int i = 1; i < m + 1; i++){
    for(int j = 10; j < d + 1; j++){
      if(j % 10 >= 2 && j / 10 >= 2 && (j % 10) * (j / 10) == i){
        ans++;
      }
    }
  }
  cout << ans << endl;
}