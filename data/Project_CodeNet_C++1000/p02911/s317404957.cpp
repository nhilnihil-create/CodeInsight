#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int N, K, Q;
  cin >> N >> K >> Q;
  int A[N];
  rep(i, N){
    A[i] = K - Q;
  }
  int a;
  rep(i, Q){
    cin >> a;
    A[a - 1]++;
  }
  rep(i, N){
    if (A[i] > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
