#include<iostream>
#include<cmath>
using namespace std;

bool sosu(int n) {
  if(n < 2) return false;//2以下除く
  else if(n == 2) return true;//2は素数
  else if(n % 2 == 0) return false;//偶数除く
  int root = sqrt(n);
  for(int i=3; i<=root; i+=2) {//奇数で割る
    if(n % i == 0) return false;
  }
  return true;
}

int main() {
  int n; cin >> n;
  int sum = 0;
  for(int i=0; i<n; i++) {
    int x;
    cin >> x;
    if(sosu(x) == true) sum++;
  }
  cout << sum << endl;
}

