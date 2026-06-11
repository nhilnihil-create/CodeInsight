#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;

double dist(double dx, double dy) {
  return sqrt(dx*dx+dy*dy);
}

int main() {
  
  int n;
  cin >> n;
  
  vector<pair<double,double>> vdd;
  
  while (n--) {
    double x, y;
    cin >> x >> y;
    
    vdd.pb(mp(x, y));
  }
  
  
  double sumEdges = 0.0;
  
  for (int i = 0; i < vdd.size(); ++i) {
    for (int j = i+1; j < vdd.size(); ++j) {
      double x1, x2, y1, y2;
      
      x1 = vdd.at(i).first;
      y1 = vdd.at(i).second;
      
      x2 = vdd.at(j).first;
      y2 = vdd.at(j).second;
      
      sumEdges += dist(x1-x2, y1-y2);
    }
  }
  
  cout << fixed << 2*sumEdges/vdd.size() << endl;
  
  return 0;
}