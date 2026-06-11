#include<iostream>
#include<vector>
#include<string>
#include<cmath>
std::vector<long long int>vec(200002,0);
std::vector<long long int>sum(2022,0);
int main(){
  std::string str;
  std::cin>>str;
    long long int s=1;
  for(int i=1;i<=str.length();i++){
      
//      std::cout<<s<<std::endl;
//      std::cout<<(str[str.length()-i]-'0')*s+vec[i-1]<<" ";
      vec[i]=((str[str.length()-i]-'0')*s)%2019+vec[i-1]%2019;
      vec[i]=vec[i]%2019;
    sum[vec[i]]++;
      
      s=10*s;
      s=s%2019;
  }
//   for(int i=1;i<=str.length();i++)
//    std::cout<<vec[i]<<" mod:" <<vec[i]%2019<<std::endl;
   
  long long int count=0;
  for(int i=0;i<sum.size();i++){
      count+=sum[i]*(sum[i]-1)/2;
  }
    count+=sum[0];
  std::cout<<count<<std::endl;
  return 0;
}
