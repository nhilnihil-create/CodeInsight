#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <cstring>
#include <cmath>
#include <iomanip>


class engine{
public:
  double X, Y;
  
  engine(double x, double y){
    X = x;
    Y = y;
  }
};

int main(){
  
  // read problem
  long long int N;
  double tmp1, tmp2;
  std::vector<class engine> engines;
  
  scanf("%lld", &N);
  for(long long int i = 0; i < N; i++){
    scanf("%lf%lf", &tmp1, &tmp2);
    engines.push_back(engine(tmp1, tmp2));
  }
  
  for(long long int i = 0; i < N; i++){
    std::cerr << "engine:" << i << " " << engines[i].X << " " << engines[i].Y << std::endl;
  }
  
  // solve problem
  double ans = 0.0;
  double nx, ny, x, y;
  
  
  for(long long int i = 0; i < 1e5; i++){
    x = 0.0;
    y = 0.0;
    nx = std::cos(2*3.141593 * (i/100000.0));
    ny = std::sin(2*3.141593 * (i/100000.0));
    for(long long int j = 0; j < N; j++){
      if(nx*engines[j].X + ny*engines[j].Y > 0){
        x += engines[j].X;
        y += engines[j].Y;
      }
    }
    ans = std::max(ans, std::sqrt(x*x+y*y));
  }
  
  std::cerr << "Answer:" << std::endl;
  std::cout << std::setprecision(20) << ans << std::endl;
  
  return 0;
}
