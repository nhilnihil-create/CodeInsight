#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) { // n が 0 になるまで
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
int main(){
    int n;
    cin >> n;
    bool ans = false;
    rep(i,3){
        if(n % 10 == 7){
            ans = true;
            break;
        }
        n /= 10;
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}