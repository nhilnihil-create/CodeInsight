#include <iostream>
#include <queue>

using namespace std;

#define int long long
#define rep(i,n) for(int i=0; i<(int)(n); i++)

signed main() {
  int k;
  cin >> k;
  queue<int> q;
  rep(i,9) q.push(i+1);
  
  while(k != 1) {
    int n = q.front(), x = n % 10;
    q.pop();
    k--;
    if(x != 0) q.push(10 * n + x - 1);
    q.push(10 * n + x);
    if(x != 9) q.push(10 * n + x + 1);
  }
  cout << q.front() << endl;
  return 0;
}