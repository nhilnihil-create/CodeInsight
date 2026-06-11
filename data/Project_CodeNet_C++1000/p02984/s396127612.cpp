#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000;
int main(){
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  long long tv = INF;
  long long fv = -1;
  while (tv - fv > 1){
    long long mv = (tv + fv) / 2;
    long long x = mv;
    for (int i = 0; i < N; i++){
      x = A[i] * 2 - x;
    }
    if (x > mv){
      fv = mv;
    } else {
      tv = mv;
    }
  }
  vector<int> ans;
  ans.push_back(tv);
  for (int i = 0; i < N - 1; i++){
    int tmp = A[i] * 2 - ans.back();
    ans.push_back(tmp);
  }
  for (int i = 0; i < N; i++){
    cout << ans[i];
    if (i < N - 1){
      cout << ' ';
    }
  }
  cout << endl;
}