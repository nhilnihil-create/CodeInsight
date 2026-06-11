#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N;
  cin >> N;

  vector<int> order(N);
  vector<int> point(N);
  vector<int> bonus(N - 1);

  for (int i = 0; i < N; i++) cin >> order.at(i);
  for (int i = 0; i < N; i++) cin >> point.at(i);
  for (int i = 0; i < N - 1; i++) cin >> bonus.at(i);

  int sum = 0;
  int before = -999;

  for (int i = 0; i < N; i++){
    sum += point.at(order.at(i) - 1);

    if (before == order.at(i) - 1) sum += bonus.at(order.at(i) - 2);

    before = order.at(i);
  }

  cout << sum << endl;
}