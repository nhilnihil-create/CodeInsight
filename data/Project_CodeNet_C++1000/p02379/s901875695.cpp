#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main(){
  cout<<fixed<<setprecision(12);
  double x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  double X=pow(x1-x2,2);
  double Y=pow(y1-y2,2);
  cout<<sqrt(X+Y)<<endl;
  return 0;
}

