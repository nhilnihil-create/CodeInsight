#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <stdio.h>
#define rep(i,o,u) for(int i = o;i <= u; i++)
typedef unsigned long long ll;
using namespace std;
struct point{
	double x;double y;
};
void solve(int n,point a,point b){
	if(n == 0) return ;
	point s,t,u;
	double th = M_PI * 60.0 / 180.0;
	s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
	s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;
	t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
	t.y = (1.0 * a.y + 2.0 * b.y) / 3.0;
	u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
	u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;
	solve(n-1,a,s);
	printf("%0.8f %0.8f\n",s.x,s.y);
	solve(n-1,s,u);
	printf("%0.8f %0.8f\n",u.x,u.y);
	solve(n-1,u,t);
	printf("%0.8f %0.8f\n",t.x,t.y);
	solve(n-1,t,b);
}
int main(){
	int n;
	cin >> n;
	point p1,p2;
	p1.x = 0;p1.y = 0;
	p2.x = 100;p2.y = 0;
	printf("%0.8f %0.8f\n",p1.x,p2.y);
	solve(n,p1,p2);
	printf("%0.8f %0.8f\n",p2.x,p2.y);
	return 0;
}