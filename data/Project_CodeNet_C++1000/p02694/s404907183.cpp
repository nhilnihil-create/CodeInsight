#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  ll X;
  cin >> X;
  ll sum = 100;
  rep(i, 1000000000){
    if(sum >= X){
      cout << i << endl;
      return 0;
    }else{
      sum += sum / 100;
    }
 }
}