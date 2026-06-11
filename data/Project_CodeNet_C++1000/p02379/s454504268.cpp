//itp1_10a
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){
 double x1,x2,y1,y2,res;

 cin>>x1>>y1>>x2>>y2;
 res=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
// cout<<res<<endl;
 printf("%.6f\n",res);
 return 0;
}