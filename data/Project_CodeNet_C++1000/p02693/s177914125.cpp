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
    long long k,a,b;
    bool ans = false;
    cin >> k >> a >> b;
    for(int i = a; i <= b; i++) {
        if(i % k == 0 ) ans = true;
        else continue;
    }   
    if(ans) cout << "OK" << endl;
    else cout << "NG" << endl;
}
