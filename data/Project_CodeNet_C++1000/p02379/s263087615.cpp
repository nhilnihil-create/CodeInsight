#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
int main(){
  double x1,x2,y1,y2,ans=0;
  cin>>x1>>y1>>x2>>y2;
  ans = sqrt(pow((x2-x1),2.0)+pow((y2-y1),2.0));
  cout<<fixed<<setprecision(4)<<ans<<endl;
  return 0;
}