#include<iostream>
#include<cmath>
#include<iomanip>
int main(){
  int n;
  double D=0;
  std::cin >> n;
  int x[n], y[n];
  for(int i=0; i<n; i++) std::cin >> x[i];
  for(int i=0; i<n; i++) std::cin >> y[i];
  for(int p=1; p<=3; p++){
    for(int i=0; i<n; i++) D += pow(std::abs(x[i]-y[i]), p);
    std::cout << std::fixed << std::setprecision(8) << pow(D, (double)1/p) << std::endl;
    D = 0;
  }
  for(int i=0; i<n; i++) if(D < std::abs(x[i]-y[i])) D = std::abs(x[i]-y[i]);
  std::cout << std::fixed << std::setprecision(8) << D << std::endl;
  return 0;
}