#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
#include<algorithm>

signed main(){

  int n;
  std::cin>>n;
  std::vector<double> x(n),y(n);
  for(auto& xi:x)std::cin>>xi;
  for(auto& yi:y)std::cin>>yi;

  auto manhattan_distance = [](auto const& x,auto const& y)->double{
    int n = x.size();
    double dist = 0.0;
    for(int i=0;i<n;++i){
      dist += std::abs(x[i]-y[i]);
    }
    return dist;
  };
  auto euclidean_distance = [](auto const& x,auto const& y)->double{
    int n = x.size();
    double dist = 0.0;
    double p = 2;
    for(int i=0;i<n;++i){
      dist += std::pow(std::abs(x[i]-y[i]),p);
    }
    dist = std::pow(dist,1.0/p);
    return dist;
  };
  auto chebyshev_distance = [](auto const& x,auto const& y)->double{
    int n = x.size();
    double dist = 0.0;
    for(int i=0;i<n;++i){
      dist = std::max(dist,std::abs(x[i]-y[i]));
    }
    return dist;
  };
  auto minkowski_distance = [](auto const& x,auto const& y,double p)->double{
    int n = x.size();
    double dist = 0.0;
    for(int i=0;i<n;++i){
      dist += std::pow(std::abs(x[i]-y[i]),p);
    }
    dist = std::pow(dist,1.0/p);
    return dist;
  };

  std::cout << std::fixed <<std::setprecision(10);

  std::cout<< minkowski_distance(x,y,1.0) <<std::endl;
  std::cout<< minkowski_distance(x,y,2.0) <<std::endl;
  std::cout<< minkowski_distance(x,y,3.0) <<std::endl;
  std::cout<< chebyshev_distance(x,y) <<std::endl;

}
