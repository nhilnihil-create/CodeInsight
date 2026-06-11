#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N, M;
  cin >> N >> M;
  int total = N + M;
  vector<int> vec;

  for (int i = 0; i < N; i++){
    vec.push_back(2 * (i + 1));
  }
  for (int i = 0; i < M; i++){
    vec.push_back(2 * i + 1);
  }

  int count = 0;
  for (int i = 0; i < vec.size(); i++){
    for (int j = i + 1; j < vec.size(); j++){
      if (i == j) continue;
      if ((vec.at(i) + vec.at(j)) % 2 == 0){
        count += 1;
      } 
    }
  }

  cout << count << endl;
}