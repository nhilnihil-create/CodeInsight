#include <iostream>
using namespace std;
int isintersecter(double x1,double y1,double x2,double y2,double px,double py,
		  double qx,double qy){
  if(((py-y1)*(x1-x2)-(y1-y2)*(px-x1))*((qy-y1)*(x1-x2)-(y1-y2)*(qx-x1)) < 0)return 1;
  else return 0;
}
int main(){
  double x1,y1,x2,y2,x3,y3,xp,xy;
  while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>xp>>xy)
    {
      if(isintersecter(x1,y1,x2,y2,x3,y3,xp,xy) || 
	 isintersecter(x2,y2,x3,y3,x1,y1,xp,xy) || 
	 isintersecter(x1,y1,x3,y3,x2,y2,xp,xy) )cout << "NO" << endl;
      else cout << "YES" << endl;
    }
}