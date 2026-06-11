#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  int i;
  int x[6];
  cin >> x[0] >> x[1] >> x[2] >> x[3] >> x[4];

  for (i = 1; i < 6; i++){
    if (x[i - 1] == 0){
      cout << i << endl;
      i = 6;
    }
  }

}