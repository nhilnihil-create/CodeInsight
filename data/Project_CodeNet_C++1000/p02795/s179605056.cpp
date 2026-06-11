#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, n, sum=0,i;
  cin >> h >> w >> n;
  for(i=0;sum<n;i++){
    sum=sum+max(h,w);
  }
  cout << i;
  return 0;
}