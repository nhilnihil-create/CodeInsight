#include<bits/stdc++.h>
using namespace std;

int main() {
  int N, point = 0, res = 0, prevres = INT_MAX;
  cin >> N;
  vector<int> vec(N);
  for(int i = 0; i < N; i++) cin >> vec[i];
  while(true) {
    for(int i = 0; i < N; i++) {
      res += (vec[i] - point) * (vec[i] - point);
    }
    if(prevres < res) {
      res = prevres;
      break;
    }
    else {
      prevres = res;
      res = 0;
      point++;
    }
  }
  cout << res << endl;
}
