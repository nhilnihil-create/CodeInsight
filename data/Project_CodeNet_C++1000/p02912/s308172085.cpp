#include <stdio.h>

#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
  priority_queue<int> q;
  int n, m;
  cin >> n >> m;
  int a;
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a);
    sum += a;
    q.push(a);
  }

  for (int i = 0; i < m; ++i) {
    int po = q.top();
    int sa = po / 2;
    sum -= po - sa;
    q.pop();
    q.push(sa);
  }

  cout << sum << endl;
}
