#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for (int i = 0; i < (n); i++)

int keta(int x) {
  int num = 0;
  while (x > 0) {
    x /= 10;
    num++;
  }
  return num;
}

int main() {
  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 1; i<n+1; i++) {
    int num = keta(i);
    if (num % 2 != 0) cnt++;
  }
  cout << cnt << endl;
}
