#include <bits/stdc++.h>
using namespace std;

int main () {
  int N;
  cin >> N;
  long long cash = 1000;
  long long stake = 0;
  vector <int> rate(N);
  for (int i = 0; i < N; i++) cin >> rate.at(i);
  for (int i = 0; i < N-1;i++){
    if (rate.at(i) <= rate.at(i+1)) {
      stake += cash/rate.at(i);
      cash %= rate.at(i);
    }
    else {
      cash += stake*rate.at(i);
      stake = 0;
    }
  }
  cash += stake*rate.at(N-1);
  cout << cash << endl;
} 