#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int a, b;
  cin >> a >> b;

  int sum = 1;
  int flag = 0;

  while (sum < b){
    sum--;
    sum += a;
    flag++;
  }

  cout << flag;
}
