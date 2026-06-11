#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
using namespace std;

struct point {
	double x;
	double y;
	point(double xi, double yi){
		this->x = xi;
		this->y = yi;
	}
};

int main() {
	int n;
	scanf("%d", &n);
	
	list<point> pts;
	pts.push_back(point(0, 0));
	pts.push_back(point(100, 0));
	
	while(n--){
		list<point>::iterator fe = pts.begin(), se;
		while(1){
			se = fe;
			if(++se == pts.end()) break;
			
			double vx = ((*se).x - (*fe).x) / 3;
			double vy = ((*se).y - (*fe).y) / 3;
			
			point npr((*fe).x + vx, (*fe).y + vy);
			point npc(npr.x + cos(M_PI / 3) * vx - sin(M_PI / 3) * vy, npr.y + sin(M_PI / 3) * vx + cos(M_PI / 3) * vy);
			point npl((*fe).x + vx * 2, (*fe).y + vy * 2);
			
			pts.insert(se, npr);
			pts.insert(se, npc);
			pts.insert(se, npl);
			
			fe = se;
		}
	}
	
	list<point>::iterator e = pts.begin();
	do{
		printf("%.8f %.8f\n", (*e).x, (*e).y);
	}while(++e != pts.end());
	
    return 0;
}