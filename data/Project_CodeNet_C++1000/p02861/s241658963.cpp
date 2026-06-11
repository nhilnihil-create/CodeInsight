#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> x(N);
  vector<int> y(N);
  for (int i = 0; i < N; i++){
    cin >> x.at(i);
    cin >> y.at(i);
  }
  int count = 1;
  for (int i = 1; i < N; i++){
    count *= i;
  }
  count *= 2;
  int A = 1;
  for (int i = 1; i <= N; i++){
    A *= i;
  }
  
  double ans = 0.0000000000;
  for (int i = 0; i < N; i++){
    for (int j = i + 1; j < N; j++){
      ans += sqrt((x.at(i) - x.at(j)) * (x.at(i) - x.at(j)) + (y.at(i) - y.at(j)) * (y.at(i) - y.at(j)));
    }
  }
  cout << fixed << setprecision(10);
  cout << count * ans / A << endl;
}

