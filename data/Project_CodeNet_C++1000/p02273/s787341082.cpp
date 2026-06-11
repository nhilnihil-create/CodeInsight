#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef long double ld;
const ld theta=M_PI/3.0;
typedef pair<ld,ld> P;
void solve(int n,P a,P b){
	if(!n)	return;
	P s,t,u;
	s.x=(2.0*a.x+b.x)/3.0;
	s.y=(2.0*a.y+b.y)/3.0;
	u.x=(a.x+2.0*b.x)/3.0;
	u.y=(a.y+2.0*b.y)/3.0;
	P vec=make_pair(u.x-s.x,u.y-s.y);
	t.x=vec.x*cosl(theta)-vec.y*sinl(theta)+s.x;
	t.y=vec.x*sinl(theta)+vec.y*cosl(theta)+s.y;
	n--;
	solve(n,a,s);
	printf("%.15Lf %.15Lf\n",s.x,s.y);
	solve(n,s,t);
	printf("%.15Lf %.15Lf\n",t.x,t.y);
	solve(n,t,u);
	printf("%.15Lf %.15Lf\n",u.x,u.y);
	solve(n,u,b);
}
int main(){
	int n;	cin>>n;
	P a=make_pair(0,0),b=make_pair(100,0);
	printf("%.15Lf %.15Lf\n",a.x,a.y);
	solve(n,a,b);
	printf("%.15Lf %.15Lf\n",b.x,b.y);
	return 0;
}