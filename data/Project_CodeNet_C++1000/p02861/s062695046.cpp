#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

double dis(int a, int b, vector<int> X, vector<int> Y){
  double c = (X[a]-X[b])*(X[a]-X[b])+(Y[a]-Y[b])*(Y[a]-Y[b]);
  return sqrt(c);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin>>n;
  
  vector<vector<int>> memo(n, vector<int>(n));
  vector<int> x(n), y(n), vec(n);
  int zyo = 1;
  rep(i, n) {
    cin >> x[i] >> y[i];
    vec[i] = i;
    zyo *= i+1;
  }
  double ans, sum = 0;
  
  do{
    rep(i, n-1) {
      sum += dis(vec[i], vec[i+1], x, y);
    }
  }while (next_permutation(vec.begin(), vec.end()));
  
  ans = sum/zyo;
  
  printf("%.7lf", ans);
}