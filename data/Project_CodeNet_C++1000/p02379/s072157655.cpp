#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main(){
double x1,y1,x2,y2;
double xlen,ylen,ans;
cin>>x1>>y1>>x2>>y2;
ans=pow(x2-x1,2)+pow(y2-y1,2);
ans=sqrt(ans);
cout<<fixed<<ans;
}
