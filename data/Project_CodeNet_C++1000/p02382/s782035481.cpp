#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

double p1 (vector<int> x, vector<int> y) {
  double d = 0;
  int len = x.size();
  for (int i = 0; i < len; i++) {
    d += abs(x[i]-y[i]);
  }
  return d;
}

double p2 (vector<int> x, vector<int> y) {
  double d = 0;
  int len = x.size();
  for (int i = 0; i < len; i++) {
    d += pow(x[i]-y[i], 2);
  }
  return sqrt(d);
}

double p3 (vector<int> x, vector<int> y) {
  double d = 0;
  int len = x.size();
  for (int i = 0; i < len; i++) {
    d += pow(abs(x[i]-y[i]), 3);
  }
  return pow(d, 1.0/3.0);
}

double p_unlimited (vector<int> x, vector<int> y) {
  double d = 0.0;
  int len = x.size();
  for (int i = 0; i < len; i++) {
    d = max(d, abs(x[i]-y[i]));
  }
  return d;
}

int main(int argc, char* argv[]) {
  int n; cin >> n;
  vector<int> x, y;

  for (int i = 0; i < n; i++) {
    int in; cin >> in;
    x.push_back(in);
  }

  for (int i = 0; i < n; i++) {
    int in; cin >> in;
    y.push_back(in);
  }

  cout << fixed << setprecision(6);
  cout << p1(x, y) << endl;
  cout << p2(x, y) << endl;
  cout << p3(x, y) << endl;
  cout << p_unlimited(x, y) << endl;
  return 0;
}