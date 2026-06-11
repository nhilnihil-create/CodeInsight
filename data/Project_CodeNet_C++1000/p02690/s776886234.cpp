#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
  int x;
  cin >> x;
  for(int i = 0; i < 1000; i++){
    for(int j = -1000; j < 1000; j++){
      ll a = pow(i,5);
      ll b = pow(j,5);
      if(a - b == x){
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }
  return 0;
}