#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)

int main(){
  int n;
  cin >> n;
  rep(i,n-1) {
    for(int  j = i+1; j < n; j++) {
      int a = j - i;
      int k = 1;
      while(a % 2 == 0) {
        a /= 2;
        k++;
      }
      cout << k << " ";
    }
    cout << endl;
  }
  return 0;
}