#include <iostream>
#include <list>
#include <utility>
#include <cmath>
#include <iomanip>

using namespace std;

class vec2d {
	public:
		double x,y;
		vec2d(double _x,double _y) {
			x = _x;y = _y;
		}
		vec2d() {
			x = 0;y = 0;
		}
		vec2d transform(double rotate,double magnify) {
			vec2d ret;
			ret.x = ((x*cos(rotate))-(y*sin(rotate)))*magnify;
			ret.y = ((x*sin(rotate))+(y*cos(rotate)))*magnify;
			return ret;
		}
		vec2d operator-(const vec2d e) const{
			return vec2d(x - e.x,y - e.y);
		}
		vec2d operator+(const vec2d e) const{
			return vec2d(x + e.x,y + e.y);
		}
};

list<vec2d> pt;

void koch(int depth,list<vec2d>::iterator p1,list<vec2d>::iterator p2) {
	if(depth == 0) return;
	vec2d dif = (*p2) - (*p1);
	pt.insert(p2,(*p1) + dif.transform(0,((double)1)/((double)3)));
	pt.insert(p2,(*p1) + dif.transform(0,((double)1)/((double)3)) + dif.transform(M_PI / ((double)3),((double)1)/((double)3)));
	pt.insert(p2,(*p1) + dif.transform(0,((double)2)/((double)3)));
	auto pp = p1;
	auto pn = p1;
	pn++;
	for(int i = 0;i < 4;i++) {
		koch(depth-1,pp,pn);
		if(i != 3) {
			pp = pn;
			pn++;
		}
	}
}

int main() {
	int n;
	cin >> n;
	pt.insert(pt.end(),vec2d(0.0,0.0));
	pt.insert(pt.end(),vec2d(100.0,0.0));
	auto pn = pt.begin();
	pn++;
	koch(n,pt.begin(),pn);
	cout << fixed << setprecision(20);
	//cout << "2500 1000 " << pt.size() << endl;
	for(auto e:pt) {
		cout << e.x << " " << e.y << endl;
	}
}

