#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  long long N, A, B;
  cin >> N >> A >> B;
  long long x = N / (A + B);
  long long y = min(A, (N % (A + B)));
  cout << A * x + y << endl;
}
