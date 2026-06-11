#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  long long N, A, B;
  cin >> N >> A >> B;
  if((B-A)%2==0) cout << (B-A)/2 << endl;
  else cout << min((N-B+1+N-A)/2, min((A+B-1)/2, min(B-1, N-A))) << endl;
}