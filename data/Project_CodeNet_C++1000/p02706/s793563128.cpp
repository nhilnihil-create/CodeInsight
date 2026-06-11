#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N, M;
  cin >> N >> M;

  int m = 0;
  int sum = 0;
  for (int i = 0; i < M; i++){
    cin >> m;
    sum += m;
  }

  cout << (N -sum < 0 ? -1 : N - sum) << endl;
}