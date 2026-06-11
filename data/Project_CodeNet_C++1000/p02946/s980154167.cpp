#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long Int;

int main(){ 
  int K, X;
  cin >> K >> X;
  
  int left, right;
  left = X - K + 1;
  right = X + K - 1;
  
  for (int i = left; i < right; i++) {
    cout << i << " ";
  }
  cout << right << endl;

}
