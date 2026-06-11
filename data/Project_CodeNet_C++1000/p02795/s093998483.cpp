#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<n;i++)
#define cY cout << "Yes" << endl;
#define cN cout << "No" << endl;

int main() {
  int h,w,n;
  cin >> h >> w >> n;
  int cnt = 0;
  while(n>0){
    n -= max(h,w);
    cnt++;
  }
  cout << cnt << endl;
}