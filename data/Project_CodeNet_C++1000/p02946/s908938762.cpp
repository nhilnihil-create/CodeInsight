#include <bits/stdc++.h>
using namespace std;

int main() {
  long long K,X;
  cin >> K >> X;
  int a = X-K+1;
  int b = X+K-1;
  for(int i=a; i<=b;i++){
    cout << i << " ";
  }
}
