#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int>p(N);
  for (int i = 0; i < N; i++) {
    cin >> p.at(i);
  }
  int count = 0;

  for (int i = 0; i < N-2; i++) {
    if (min(p.at(i),p.at(i+1)) == p.at(i+1) && max(p.at(i+1),p.at(i+2)) == p.at(i+1)){
      count++;
    }
    else if (max(p.at(i),p.at(i+1)) == p.at(i+1) && min(p.at(i+1),p.at(i+2)) == p.at(i+1)){
      count++;
    }
  }
  cout << count << endl;
}

