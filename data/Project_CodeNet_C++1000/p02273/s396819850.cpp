#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#define _USE_MATH_DEFINES
using namespace std;
vector<double> x;
vector<double> y;

void solve(int N){
  if(N > 0){
    vector<double> xx;
    vector<double> yy;
    xx.push_back(x[0]);
    yy.push_back(y[0]);
    double px = x[0];
    double py = y[0];
    int size = x.size();
    double tmpx[4];
    double tmpy[4];
    for(int i = 1; i < size; i++){
      double qx = x[i];
      double qy = y[i];
      double sx = (2.0 * px + qx) / 3.0;
      double sy = (2 * py + qy) / 3.0;
      double tx = (px + 2.0 * qx) / 3.0;
      double ty = (py + 2.0 * qy) / 3.0;
      double angle = atan2(ty - sy, tx - sx);
      double radius = sqrt((ty - sy) * (ty - sy) + (tx - sx) * (tx - sx));
      double mx = sx + radius * cos(angle + M_PI / 3.0);
      double my = sy + radius * sin(angle + M_PI / 3.0);
      tmpx[0] = sx;
      tmpx[1] = mx;
      tmpx[2] = tx;
      tmpx[3] = qx;
      tmpy[0] = sy;
      tmpy[1] = my;
      tmpy[2] = ty;
      tmpy[3] = qy;
      for(int j = 0; j < 4; j++){
	xx.push_back(tmpx[j]);
	yy.push_back(tmpy[j]);
      }
      px = qx;
      py = qy;
    }
    x = xx;
    y = yy;
    solve(N - 1);
  }
}

int main() {
  int N;
  cin >> N;
  x.push_back(0);
  y.push_back(0);
  x.push_back(100);
  y.push_back(0);
  solve(N);
  for(int i = 0; i < x.size(); i++){
    cout << x[i];
    cout << " ";
    cout << y[i] << endl;
  }
}

//鶴崎 修功 45-186020
//平安京ウォーキング https://onlinejudge.u-aizu.ac.jp/#/problems/2186
//教卓から見て中央・中央あたりに座っていました。
