#include <bits/stdc++.h>
#define repr(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
#define reprrev(i, a, b) for (int i = b - 1; i >= a; i--) // [a, b)
#define reprev(i, n) reprrev(i, 0, n)


using namespace std;
double length_road(pair<double, double> a, pair<double, double> b) {
  double distance = sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
  return distance;
}

int main() {
  int N; cin >> N;
  int ave = 1;
  for(int i = 1; i <= N; i++) {
    ave *= i;
  }
  vector<pair<double, double>> L;
  rep(i, N) {
    double a, b;
    cin >> a >> b;
    L.emplace_back(a, b);
  }

  sort(L.begin(), L.end());


  double sum = 0;
  do {
    for(int i = 0; i < N-1; i++) {
      auto a = L.at(i);
      auto b = L.at(i+1);
      sum += length_road(a, b);
    }
  } while(next_permutation(L.begin(), L.end()));

  cout << fixed << setprecision(10) << sum/ave << endl;
}