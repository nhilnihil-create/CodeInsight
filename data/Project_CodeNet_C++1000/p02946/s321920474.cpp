
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int K, X;
  cin >> K >> X;

  int left;
  if (X - K + 1 >= -1000000){
    left = X - K + 1;
  }
  else
  {
    left = -1000000;
  }

  int right;
  if (X + K - 1 <= 1000000){
    right = X + K - 1;
  }
  else
  {
    right = 1000000;
  }

  for (int i = left; i <= right; i++){
    cout << i;
    if (i != right) cout << " ";
  }

  cout << "" << endl;
  
}