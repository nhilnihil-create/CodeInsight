#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;
  
int x[8], y[8];

double dist(int a, int b){
  return sqrt(pow((x[a] - x[b]), 2) + pow((y[a] - y[b]), 2));
}

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  double ret = 0;
  vector<vector<double>> d(n, vector<double>(n)); //distance A to B

  vector<int> path(n); // 初期順列
  for(int i = 0; i < n; i++) path[i] = i;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == j) {
        d[i][j] = 0;
      } else {
        d[i][j] = dist(i, j);
      }
    }
  }

  vector<double> route;
  do {
    double tmp_route = 0;
    for(int i = 0; i < n-1; i++) {
      tmp_route += d[path[i]][path[i+1]];
    }
    route.push_back(tmp_route);
  } while(next_permutation(path.begin(), path.end()));

  cout << fixed << setprecision(7) \
      << accumulate(route.begin(), route.end(), 0.0)/route.size() << endl;

  return 0;
}
