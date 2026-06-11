#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
int main(){
  int n,k;
  std::cin>>n>>k;
  std::vector<double> a(n),b(n);
  for(auto& ai:a)std::cin>>ai;
  auto f = [](double x){return x*(x+1)/2/x;};
  for(int i=0;i<n;++i)b[i]=f(a[i]);
  std::vector<double> acc(n+1);
  for(int i=0;i<n;++i)acc[i+1]=acc[i]+b[i];
  double ans = 0.0;
  for(int i=0;i+k<=n;++i)ans = std::max(ans,acc[i+k]-acc[i]);
  std::cout<<std::fixed<<std::setprecision(10)<<ans<<std::endl;
}
