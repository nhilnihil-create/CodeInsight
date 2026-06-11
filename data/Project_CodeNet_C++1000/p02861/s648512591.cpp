#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<pair<int, int>> v(n);
  vector<int> city(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    v[i] = make_pair(x, y);
    city[i] = i;
  }
  double sumleng = 0.00000000;
  do {
    double leng = 0.00000000;
    for(int i = 1; i < n; i++) {
      int mae = city[i-1], ato = city[i];
      int dx = v[ato].first - v[mae].first, dy = v[ato].second - v[mae].second;
      leng += sqrt(dx*dx + dy*dy);
    }
    sumleng += leng;
  } while (next_permutation(city.begin(), city.end()));
  int route = 1;
  while(n > 1) {
    route *= n;
    n--;
  }
  cout << setprecision(14);
  cout << sumleng / (double)route;
}