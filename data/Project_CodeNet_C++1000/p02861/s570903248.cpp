#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  int N;
  cin >> N;
  
  vector<pair<double,double>> town(N);
  for (int i = 0; i < N; i++) {
    double x, y;
    cin >> x >> y;
    town[i] = {x, y};
  }
  
  int perm[N];
  for (int i = 0; i < N; i++) {
    perm[i] = i;
  }
  double count = 0;
  double sum = 0;
  // 平均距離の計算
  do {
    count++;
    double subsum = 0;
    for (int i = 0; i < N-1; i++) {
      pair<double,double> p = town[perm[i]], q = town[perm[i+1]];
      subsum += sqrt((p.first - q.first) * (p.first-q.first)
        + (p.second - q.second) * (p.second - q.second));
      
    }
    
    sum += subsum;
  } while(next_permutation(perm, perm+N));
  
  
  cout << fixed << setprecision(10) << sum / count << endl;
}