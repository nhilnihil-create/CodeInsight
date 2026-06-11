#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t M;
  cin >> M;
  int64_t sum = 0;
  int64_t ans = 0;
  for(int i=0; i<M; i++){
    int64_t x, y;
    cin >> x >> y;
    ans += y;
    sum += x*y;
  }
  cout << (ans - 1) + (sum-1)/9 << endl;
} 