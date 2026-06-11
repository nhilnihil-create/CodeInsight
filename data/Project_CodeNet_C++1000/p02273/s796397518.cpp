#include<bits/stdc++.h>
using namespace std;
int a[21],c[21];
bool b[21];
bool f;
int n,m,q,x,l; 
struct Point{
	  double x,y;
};
void koch(int d,Point p1,Point p2){
	 if (d==0) return;
	 Point s,u,t;
	 s.x=((p2.x-p1.x)/3.0+p1.x);
	 s.y=((p2.y-p1.y)/3.0+p1.y);
	 t.x=(p2.x-(p2.x-p1.x)/3.0);
	 t.y=(p2.y-(p2.y-p1.y)/3.0);
	 u.x=(t.x-s.x)*0.5-(t.y-s.y)*(sqrt(3)/2.0)+s.x;
	 u.y=(t.x-s.x)*(sqrt(3)/2.0)+(t.y-s.y)*0.5+s.y;
	 koch(d-1,p1,s);
	 printf("%.8f %.8f\n",s.x,s.y);
	 koch(d-1,s,u);
	 printf("%.8f %.8f\n",u.x,u.y);
	 koch(d-1,u,t);
	 printf("%.8f %.8f\n",t.x,t.y);
	 koch(d-1,t,p2);
}
int main(){
    cin>>n;
    Point p1,p2;
    p1.x=0; p2.x=100;
    p1.y=0; p2.y=0;
    printf("%.8f %.8f\n",p1.x,p1.y);
    koch(n,p1,p2);
    printf("%.8f %.8f\n",p2.x,p2.y);
	return 0;
}
