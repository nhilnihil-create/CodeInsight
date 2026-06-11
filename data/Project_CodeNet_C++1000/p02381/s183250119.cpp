#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
  int i,n;
  double sum = 0;
  double a,average;
  while(1){
    sum = 0;
    int s[1001]={};
    average = 0;
    cin>>n;
    if(n == 0){break;}
  for(i = 0;i < n;i++){
    cin>>s[i];
    sum += s[i];
  }
  average = sum/(double)n;
  sum = 0;
  for(i = 0;i < n;i++){
    sum += pow(((double)s[i]-average),2.0);
  }
  a = sqrt(sum/(double)n);
  cout<<fixed<<setprecision(4)<<a<<endl;
}
  return 0;
}