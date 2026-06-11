#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> data(N);
  for(int i = 0; i < N; i++) {
    cin >> data.at(i);
  }
  int now = 0;
  int count = 1;
  for(int i = 0; i < N; i++) {
    now += data.at(i);
    if(now <= X) {
      count++;
    }
  }
  cout << count << endl; 
}