#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <tuple>
#include <algorithm>

using lli=long long int;
const double PI=4*std::atan(1);

struct p{
  p(int _x, int _y, double _t): x(_x),y(_y),t(_t) {}
  int x,y;
  double t;
};

int main(){
  int N;
  std::cin >> N;

  std::vector<p> p_arr;
  for(int i = 0; i < N; i++){
    int x,y;
    std::cin >> x >> y;
    double t = std::atan2(x,y);
    p_arr.emplace_back(x,y,t);
  }

  std::sort(p_arr.begin(), p_arr.end(), [](p& l, p& r){ return l.t < r.t; });
  std::vector<p> p2_arr(p_arr);
  p2_arr.insert(p2_arr.end(), p_arr.begin(), p_arr.end());
  std::vector<p> sum_arr;
  lli xs=0, ys=0;
  sum_arr.emplace_back(xs, ys, 0.0);
  for(auto&& it: p2_arr){
    xs += it.x;
    ys += it.y;
    sum_arr.emplace_back(xs, ys, 0.0);
  }
  lli r2_max = 0;
  for(int i = 0; i <= N; i++){
    for(int j = 0; j <= N; j++){
      lli xd = sum_arr[i+j].x-sum_arr[i].x;
      lli yd = sum_arr[i+j].y-sum_arr[i].y;
      r2_max = std::max(r2_max, xd*xd+yd*yd);
    }
  }

  std::cout << std::setprecision(40) << std::fixed << std::sqrt(1.0*r2_max) << std::endl;
  return 0;
}

