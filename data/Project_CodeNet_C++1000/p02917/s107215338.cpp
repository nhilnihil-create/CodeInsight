#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> D(N - 1);
  for (int i = 0; i < N - 1; i++){
    cin >> D.at(i);
  }
  int sum = 0;
  sum += D.at(0);
  for (int i = 1; i < N - 1; i++){
    sum += min(D.at(i - 1), D.at(i));
  }
  sum += D.at(N - 2);
  cout << sum << endl;
  return 0;
}