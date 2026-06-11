#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int N;
  cin >> N;
  int A[N];
  rep(i, N){
    cin >> A[i];
  }
  double ans=0;
  rep(i, N){
    ans += (1.0/A[i]);
  }
  cout << fixed << setprecision(10);
  cout << 1.0 / ans << endl;
}
