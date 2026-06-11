#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y;
  cin >> x >> y;
  int flag = 0;
  for (int i = 0; i <= x; i++){
    if ((y-2*i)%4 == 0 && (y - 2 * i)/4 == x-i){
      flag++;
      cout << "Yes" << endl;
      break;
      }
    }
  if (flag == 0){
    cout << "No" << endl;
  }
}