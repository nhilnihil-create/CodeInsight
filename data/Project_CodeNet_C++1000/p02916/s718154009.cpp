#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans = 0;
  vector<int> dish(N);
  vector<int> add(N);
  for(int i = 0; i < N; i++) {
    int a;
    cin >> a;
    dish.at(i) = a - 1;
  }
  for(int i = 0; i < N; i++) {
    int b;
    cin >> b;
    ans += b;
  }
  for(int i = 0; i < N; i++) {
    cin >> add.at(i);
  }
  for(int i = 0; i < N - 1; i++) {
    if(dish.at(i) + 1 == dish.at(i + 1)) {
      ans += add.at(dish.at(i));
    }
  }
  cout << ans << endl;
}