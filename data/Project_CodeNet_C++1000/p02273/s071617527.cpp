#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <math.h>
#include <set>
  
#define REP(i,n)for (int i=0;i<(n);i++)
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define ll long long
using namespace std;

int n;

void rec(int depth,double ax,double ay,double dx,double dy){
	if(depth>=n)return;
	double bx=(ax+ax+dx)/3.0;
	double by=(ay+ay+dy)/3.0;
	double cx=(ax+dx+dx)/3.0;
	double cy=(ay+dy+dy)/3.0;

	double vx=cx-bx;
	double vy=cy-by;

	double mx=bx+vx/2.0-vy*sqrt(3.0)/2.0;
	double my=by+vy/2.0+vx*sqrt(3.0)/2.0;

	rec(depth+1,ax,ay,bx,by);
	printf("%.10f %.10f\n",bx,by);
	rec(depth+1,bx,by,mx,my);
	printf("%.10f %.10f\n",mx,my);
	rec(depth+1,mx,my,cx,cy);
	printf("%.10f %.10f\n",cx,cy);
	rec(depth+1,cx,cy,dx,dy);
	
}

int main(){
	cin>>n;
	double ax=0.0;
	double ay=0.0;
	double dx=100.0;
	double dy=0.0;
	printf("%.10f %.10f\n",ax,ay);
	rec(0,ax,ay,dx,dy);
	printf("%.10f %.10f\n",dx,dy);
}
