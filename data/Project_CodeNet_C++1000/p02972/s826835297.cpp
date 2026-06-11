#include<iostream>
#include<vector>
signed main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n);
  for(auto& ai:a)std::cin>>ai;
  a.insert(std::begin(a),0);
  std::vector<int> b(n+1);
  int m = 0;
  for(int i=n;i>0;i--){
    int t = a[i];
    for(int j=i;j<=n;j+=i)t^=b[j];
    b[i] = t;
    m += b[i];
  }
  std::cout<< m <<std::endl;
  for(int i=1;i<=n;++i)if(b[i])std::cout<< i <<std::endl;
}