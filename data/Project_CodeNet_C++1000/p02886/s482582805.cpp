#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N;
  cin >> N;
  vector<int> vec(N);
  for (int i = 0; i < N; i++) cin >> vec.at(i);

  int sum = 0;
  for (int i = 0; i < N - 1; i++){
    for (int j = i + 1; j < N; j++){
        sum += vec.at(i) * vec.at(j);
    }
  }

  cout << sum << endl;
}