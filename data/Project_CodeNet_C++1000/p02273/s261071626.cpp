#include <iostream>
#include<math.h>
#include<algorithm>
using namespace std;

#define FOR(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define REP(i,n) FOR((i),0,(n))
#define LL long long
#define M_PIn 3.141592653589793

struct Point{double x,y;};

void koch(int n, Point a, Point b) {
	if(n==0)return;
	Point s,t,u;
	double th=M_PIn*60.0/180.0;//??????????????¢??????

	s.x = (2.*a.x + 1.*b.x) / 3.;
	s.y = (2.*a.y + 1.*b.y) / 3.;
	t.x = (1.*a.x + 2.*b.x) / 3.;
	t.y = (1.*a.y + 2.*b.y) / 3.;
	u.x = (t.x - s.x)*cos(th) - (t.y - s.y)*sin(th) + s.x;
	u.y = (t.x - s.x)*sin(th) + (t.y - s.y)*cos(th) + s.y;

	koch(n - 1, a, s);
	cout << s.x << " " << s.y << endl;
	koch(n - 1, s, u);
	cout << u.x << " " << u.y << endl;
	koch(n - 1, u, t);
	cout << t.x << " " << t.y << endl;
	koch(n - 1, t, b);
}

int main() {
	Point a,b;
	int n;
	cin>>n;

	a.x=0;
	a.y=0;
	b.x=100;
	b.y=0;

	cout << a.x << " " << a.y << endl;
	koch(n,a,b);
	cout << b.x << " " << b.y << endl;

	//cin>>n;
	return 0;
}