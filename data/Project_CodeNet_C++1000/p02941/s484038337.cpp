#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

#define debug(x) cout << #x << ": " << x << endl;
#define ll long long

int N;
ll A[1<<20], B[1<<20], ans = 0;
queue<int> q;

bool satisfy(int i) {
  int a = B[(i - 1 + N) % N];
  int b = B[i];
  int c = B[(i + 1) % N];

  return (B[i] > A[i]) && (b > (a + c));
}

void perform_ops(int i) {
  int a = B[(i - 1 + N) % N];
  int b = B[i];
  int c = B[(i + 1) % N];

  ll n = (b - A[i]) / (a + c);
  ans += n;
  B[i] -= n * (a + c);
}

/*
b - n*(a + c) >= A[i]
n <= (b- A[i])/(a+c)

*/



int main() {
  //freopen("input.in","r",stdin);
  //freopen("output.out","w",stdout);

  cin >> N;
  for(int i = 0;i < N;i++) cin >> A[i];
  for(int i = 0;i < N;i++) cin >> B[i];

  for(int i = 0;i < N;i++) {
    if(B[i] < A[i]) {
      cout << "-1" << endl;
      return 0;
    }

    if(satisfy(i)) {
      q.push(i);
    }
  }

  while(! q.empty()) {
    int i = q.front();
    q.pop();

    perform_ops(i);
    if(satisfy(i)) {
      cout << "-1" << endl;
      return 0;
    }

    if(satisfy((i - 1 + N) % N)) {
      q.push((i - 1 + N) % N);
    }
    if(satisfy((i + 1) % N)) {
      q.push((i + 1) % N);
    }
  }

  for(int i = 0;i < N;i++) {
    if(B[i] != A[i]) {
      cout << "-1" << endl;
      return 0;
    }
  }

  cout << ans << endl;

  return 0;
}
