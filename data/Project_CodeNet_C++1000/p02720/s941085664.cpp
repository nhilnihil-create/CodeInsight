#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int K;
  cin >> K;
  queue<ll> que;
  for (int i=1; i<=9; i++) que.push(i);
  for (int i=0; i<K; i++) {
    ll x = que.front();
    if (i==K-1) {
      cout << x << endl;
      return 0;
    }
    que.pop();
    if (x%10!=0) que.push(10*x+(x%10)-1);
    que.push(10*x+x%10);
    if (x%10!=9) que.push(10*x+(x%10)+1);
  }
}