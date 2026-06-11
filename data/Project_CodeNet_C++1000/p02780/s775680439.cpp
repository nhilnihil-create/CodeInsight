#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  double s = 0.0;
  cin >> N >> K;
  vector<double> p(N);
  for (int i = 0; i < N; i++){
    double P;
    cin >> P;
    p.at(i) = (P+1.0) / 2.0;
  }
  for (int i = 0; i < K; i++){
    s += p.at(i);
  }
  double ans = s;
  for (int i = 0; i < N-K; i++){
    s += p.at(K + i) - p.at(i);
    if (ans < s){
      ans = s;
    }
  }
  cout << fixed << setprecision(15) << ans << endl;
}