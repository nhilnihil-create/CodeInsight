#include<iostream>
#include<string>
#include<iomanip>
#include<math.h>
using namespace std;
int main(){
	double x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;
	double x=(x1-x2)*(x1-x2),y=(y1-y2)*(y1-y2);
	cout<<fixed<<setprecision(10)<<(double)sqrt((double)x+y)<<endl;
	return 0;
}