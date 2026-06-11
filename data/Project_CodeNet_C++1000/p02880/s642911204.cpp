#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
int main(void){
  int n;
  cin >> n;
  int a, b;
  for(a = 1; a <= 9; a++){
      for(b = 1; b <= 9; b++){
          if(a * b == n){
              cout << "Yes" << endl;
              return 0;
          }
      }
  }
  cout << "No" << endl;
  return 0;
}