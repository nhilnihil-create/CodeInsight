#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N;
  cin >> N;
  int A[N];
  rep(i,N) cin >> A[i];

  bool approved = true;
  rep(i,N){
    if (A[i] % 2 == 0 && A[i] % 3 != 0 && A[i] % 5 != 0){
      approved = false;
    }
  }
  if (approved) cout << "APPROVED" << endl;
  else cout << "DENIED" << endl;
}
