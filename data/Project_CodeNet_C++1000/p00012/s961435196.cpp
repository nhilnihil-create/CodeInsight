#include <iostream>
#include <fstream>
#include <typeinfo>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <iomanip>
#include <cctype>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<25;
const double pi=acos(-1);
const double eps=1e-8;
const vi emp;

double add_double(double a,double b){
	if(abs(a+b)<eps*(abs(a)+abs(b))) return 0;
	return a+b;
}

struct point{
	double x,y;
	point operator+(point p){
		return point{add_double(x,p.x),add_double(y,p.y)};
	}
	point operator-(point p){
		return point{add_double(x,-p.x),add_double(y,-p.y)};
	}
	point operator*(double p){
		return point{x*p,y*p};
	}
	point operator/(double p){
		if(!p) return point{0,0}; 
		return point{x/p,y/p};
	}
	bool operator==(point p){
		return fabs(add_double(x,-p.x))<eps&&fabs(add_double(y,-p.y))<eps;
	}
	bool operator<(point p){
		if(fabs(x-p.x)>eps) return x<p.x;
		return y<p.y;
	}
};
 
typedef pair<point,point> pp;
typedef vector<point> VP;
const point O{0,0};
 
class Geom{
	public:
	double Length(point x,point y){
		point z=y-x;
		return z.x*z.x+z.y*z.y;
	}
	double IP(point p,point q){
		return p.x*q.x+p.y*q.y;
	}
	double CP(point p,point q){
		return p.x*q.y-q.x*p.y;
	}
	string Containment_polyon_point(VP p,point x){
		bool flag=0;
		p.push_back(p[0]);
		for(VP::iterator i=p.begin();i!=p.end()-1;i++){
			point a=*i-x,b=*(i+1)-x;
			if(a.y>b.y) swap(a,b);
			double ip=IP(a,b),cp=CP(a,b);
			if(a.y<=0&&b.y>0&&cp<0) flag=!flag;
			if(cp<eps&&cp>-eps&&ip<=0) return "On_side";
		}
		return flag?"Containment":"not_Containment";
	}
	void Point_in(point& p){
		cin>>p.x>>p.y;
	}
	void Point_out(point p){
		cout<<p.x<<' '<<p.y<<endl;
	}
};

VP Tri(3);
point p;

int main(){
	Geom geo;
	while(cin>>Tri[0].x){
		cin>>Tri[0].y;
		geo.Point_in(Tri[1]);
		geo.Point_in(Tri[2]);
		geo.Point_in(p);
		string s=geo.Containment_polyon_point(Tri,p);
		if(s=="Containment") cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}