#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N, X;
  cin >> N >> X;

  vector<int> vec(N);

  for (int i = 0; i < N; i++){
    cin >> vec.at(i);
  }

  vector<int> dist(N + 1);
  int cnt = 0;
  for (int i = 0; i < N + 1; i++){
    if (i == 0){
     dist.at(i) = 0;
    }
    else
    {
      dist.at(i) = dist.at(i - 1) + vec.at(i - 1);
    }
  }

  for (int i = 0; i < N + 1; i++){
    if (dist.at(i) > X) break;
    cnt += 1;
  }

  cout << cnt << endl;
}