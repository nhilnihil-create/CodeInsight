#include <bits/stdc++.h>
using namespace std;

int main(){
  int K, A, B;
  cin >> K >> A >> B;
  
  int ans = 0;
  for (int i=A ; i<=B ; i++){
    if (i%K == 0){
      ans = 1;
      break;
    }
  }
  
  if (ans == 1)
    cout << "OK" << endl;
  else
    cout << "NG" << endl;
}