#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, s, n) for(int i = s; i < n; i++)
#define repr2(i, s, n) for(int i = n-1; i >= s; i--)
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n+1), b(n+1, 0);
  rep2(i, 1, n+1) cin >> a[i];
  int m = 0;
  repr2(i, 1, n+1){
    int x = 2;
    int flag = 0;
    while(i * x <= n){
      if (b[i*x] == 1) flag = (flag + 1) % 2;
      x++;
    }
    if (a[i] != flag){
      m++;
      b[i] = 1;
    }
  }
  
  cout << m << endl;
  int cnt = 0;
  rep2(i, 1, n+1){
    if (b[i] == 1){
      cnt++;
      if (cnt == m) cout << i << endl;
      else cout << i << ' ';
    }
  }
  
  return 0;
}