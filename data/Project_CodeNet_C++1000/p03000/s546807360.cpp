#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, x, cnt = 1, sum = 0, j;
  cin >> n >> x;
  for(int i = 0; i < n; i++) {cin >> j; sum += j; if(sum<=x)cnt++;}
  cout << cnt;
}  