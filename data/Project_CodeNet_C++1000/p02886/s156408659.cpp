#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, sum=0;
  cin >> N;
  vector<int> d(N);
  for(int i=0; i<N; i++) cin >> d.at(i);
  
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      if(i != j) sum += d.at(i)*d.at(j);
    }
  }
  cout << sum/2 << endl;
}