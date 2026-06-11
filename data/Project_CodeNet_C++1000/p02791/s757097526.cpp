#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A=0,S=1;
  cin >> N;
  vector<int> vec(N);
  for(int i = 0;i < N;i++) {
    cin >> vec.at(i);
  }
  A += vec.at(0);
  for(int i = 1;i < N;i++) {
    if(A > vec.at(i)) {
      S++;
      A = vec.at(i);
    }
  }
  cout << S << endl;
}
