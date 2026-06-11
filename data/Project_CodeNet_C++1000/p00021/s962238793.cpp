#include <iostream>
#include <cmath>
using namespace std;
class point{ // as necessary
	public:
		static const int COUNTER_CLOCKWISE=1;
		static const int CLOCKWISE=-1;
		static const int ONLINE_BACK=2;
		static const int ONLINE_FRONT=-2;
		static const int ON_SEGMENT=0;
		static const double EPS=1e-10;
		double x;
		double y;
		point(double x=0,double y=0):x(x),y(y){}

		point operator+(point p){return point(x+p.x,y+p.y);}
		point operator-(point p){return point(x-p.x,y-p.y);}
		point operator*(double a){return point(x*a,y*a);}
		point operator/(double a){return point(x/a,y/a);}

		static double dot(const point &p1,const point &p2){
			return p1.x*p2.x+p1.y*p2.y;
		}

		double norm(){
			return x*x+y*y;
		}

		double abs(){
			return sqrt(norm());
		}

		static double cross(point p1,point p2){
			return p1.x*p2.y-p1.y*p2.x;
		}

		static int ccw(point p0,point p1,point p2){
			point a=p1-p0; // ??????p0p1
			point b=p2-p0; // ??????p0p2
			if(cross(a,b)>EPS) return COUNTER_CLOCKWISE; // a????????????b??????????¨?
			if(cross(a,b)<-EPS) return CLOCKWISE; // a????????????b???????¨?
			if(dot(a,b)<-EPS) return ONLINE_BACK; // p2-p0-p1???????????¢???
			if(a.norm(),b.norm()) return ONLINE_FRONT; // p0-p1-p2???????????¢???
			return ON_SEGMENT; // p0-p2-p1???????????¢???
		}
};

int main(void){
	int n;
	double x,y;
	cin>>n;
	while(n--){
		cin>>x>>y;
		point a(x,y);
		cin>>x>>y;
		point b(x,y);
		cin>>x>>y;
		point c(x,y);
		cin>>x>>y;
		point d(x,y);
		if(fabs(point::cross(b-a,d-c))<point::EPS)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}