#include <iostream>
using namespace std;

typedef struct {
	double x;
	double y;
}vector;

bool ex_product(double x0,double y0,double x1,double y1,double xp,double yp ){
	vector a={x1-x0,y1-y0};
	vector b={xp-x0,yp-y0};

	return (a.x*b.y-a.y*b.x)>=0;
}

int main(int argc, char *argv[]){
    
	double x1,y1,x2,y2,x3,y3,xp,yp;
	while(cin >> x1>>y1>>x2>>y2>>x3>>y3>>xp>>yp){
	
		bool a=ex_product(x1,y1,x2,y2,xp,yp); 
		bool b= ex_product(x2,y2,x3,y3,xp,yp) ;
		bool c=ex_product(x3,y3,x1,y1,xp,yp) ;
	
		if((a && b && c) || ((!a) && (!b) && (!c)))cout <<"YES"<<endl;
		else cout <<"NO"<<endl;
	}
	
    return 0;
}