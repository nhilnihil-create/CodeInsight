#include <bits/stdc++.h>
using namespace std;

int zettai(int x){
  if(x < 0) x *= (-1);
  return x;
}
 
int main() {
  int N, T = 0;
  cin >> N;
  vector<int> w(N);
  int sum = 0;
  for(int i = 0; i < N; i++){
    cin >> w.at(i);
    sum += w.at(i);
  }
  int minw = 100000;
  for(int i = 0; i < N; i++){
    int sumt = 0;
    for(int j = 0; j < i; j++){
      sumt += w.at(j);
    }
    minw = min(zettai(2*sumt - sum), minw);
  }
  cout << minw << endl;
}
      
      