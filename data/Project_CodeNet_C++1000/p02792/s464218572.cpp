#include<iostream>
#include<vector>
int main(){
  long long a,b=1,kotae=0;
  std::cin>>a;
  std::vector<std::vector<int> >ans(11,std::vector<int>(11,0));
  for(int i=0;i<=a;i++){
    if(i>=b*10)b=b*10;
   ans[i-i/10*10][i/b]=ans[i-i/10*10][i/b]+1;
  }
  for(int i=1;i<10;i++){
    for(int j=1;j<10;j++){
      kotae=kotae+ans[i][j]*ans[j][i];
    }
  }
  std::cout<<kotae<<std::endl;
  return 0;
}