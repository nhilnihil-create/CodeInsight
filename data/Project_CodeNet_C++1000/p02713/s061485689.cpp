#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a % b == 0){
        return b;
    }else{
        return(gcd(b, a % b));
    }
}

int main() {
  int n;
  cin >> n;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= n; k++) {
            sum += gcd(i, gcd(j, k));
        }
    }
  }
  cout << sum;
}