#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> vec(n, 0);
  reps(i, 1, n+1) {
    vector<int> seen(n+1, 0);
    vector<int> dist(n+1, 0);
    seen.at(i) = 1;
    dist.at(i) = 0;
    queue<int> que;
    que.push(i);
    while(!que.empty()) {
      int cv = que.front();
      que.pop();
      if (cv == x) {
        if (!seen.at(y)) {
          seen.at(y) = 1;
          dist.at(y) = dist.at(cv)+1;
          que.push(y);
        }
      }
      if (cv == y) {
        if (!seen.at(x)) {
          seen.at(x) = 1;
          dist.at(x) = dist.at(cv)+1;
          que.push(x);
        }        
      }
      if (cv - 1 > 0) {
        if (!seen.at(cv-1)) {
          seen.at(cv-1) = 1;
          dist.at(cv-1) = dist.at(cv)+1;
          que.push(cv-1);
        }
      }
      if (cv + 1 < n+1) {
        if (!seen.at(cv+1)) {
          seen.at(cv+1) = 1;
          dist.at(cv+1) = dist.at(cv)+1;
          que.push(cv+1);
        }        
      }
    }
    reps(j, 1, n+1) vec.at(dist.at(j))++;
  }
  
  reps(i, 1, n) {
    cout << vec.at(i)/2 << endl;
  }
  return 0;
}