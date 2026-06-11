#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N, K;
  cin >> N >> K;

  vector<int> vec(N);

  for (int i = 0; i < N; i++){
    cin >> vec.at(i);
  }

  int cnt = 0;
  for (int i = 0; i < N; i++){
    if (K <= vec.at(i)) cnt += 1;
  }

  cout << cnt << endl;
}