#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctype.h>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <math.h>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

class Point{
public:
	double x,y;
};

void koch(int n,Point a,Point b){
	Point s,t;
	if(n==0) return;
	s.x = (2*a.x+b.x)/3;
	s.y = (2*a.y+b.y)/3;
	t.x = (a.x+2*b.x)/3;
	t.y = (a.y+2*b.y)/3;
	Point u;
	double rad = M_PI*(60.0/180.0);
	u.x = (t.x-s.x)*cos(rad) - (t.y-s.y)*sin(rad) + s.x;
	u.y = (t.x-s.x)*sin(rad) + (t.y-s.y)*cos(rad) + s.y;
	koch(n-1,a,s);
	cout << s.x << " " << s.y << endl;
	koch(n-1,s,u);
	cout << u.x << " " << u.y << endl;
	koch(n-1,u,t);
	cout << t.x << " " << t.y << endl;
	koch(n-1,t,b);
}

int main(){
	int n;
	cin >> n;
	Point a,b;
	a.x = 0;a.y = 0;
	b.x = 100;b.y = 0;
	cout << fixed << setprecision(8) << a.x << " " << a.y << endl;
	koch(n,a,b);
	cout << fixed << setprecision(8) << b.x << " " << b.y << endl;
	return 0;
}