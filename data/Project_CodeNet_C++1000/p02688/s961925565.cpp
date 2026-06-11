#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N, K;
  cin >> N >> K;

  vector<int> vec(K);
  set<int> S;
  int candy;
  for (int i = 0; i < K; i++){
    cin >> vec.at(i);
    for (int j = 0; j < vec.at(i); j++){
      cin >> candy;
      S.insert(candy);
    }
  }

  int cnt = 0;
  for (int i = 1; i <= N; i++){
    if (!S.count(i)) cnt += 1;
  }

  cout << cnt << endl;
}