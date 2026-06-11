#include <bits/stdc++.h>
using namespace std;

int main(){
  long long x, p = 100;
  int cnt = 0;
  cin >> x;
  while(p < x){
    p += p / 100;
    cnt++;
  }
  cout << cnt << endl;
  return 0;
}