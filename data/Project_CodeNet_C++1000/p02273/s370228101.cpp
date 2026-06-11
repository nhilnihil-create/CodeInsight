#include<iostream>
#include<cmath>
#include<cstdio>
struct Point{
	double x;
	double y;
};
void kock(int n,struct Point p1,struct Point p2){
	if(n==0){
		return;
	}
	Point s,t,u;
	s.x=(2*p1.x+p2.x)/3.0;
	s.y=(2*p1.y+p2.y)/3.0;
	t.x=(p1.x+2*p2.x)/3.0;
	t.y=(p1.y+2*p2.y)/3.0;
	u.x=(t.x-s.x)*cos((60*M_PI)/180)-(t.y-s.y)*sin((60*M_PI)/180)+s.x;
	u.y=(t.x-s.x)*sin((60*M_PI)/180)+(t.y-s.y)*cos((60*M_PI)/180)+s.y;
	
	kock(n-1,p1,s);
	printf("%.8f %.8f\n",s.x,s.y);
	kock(n-1,s,u);
	printf("%.8f %.8f\n",u.x,u.y);
	kock(n-1,u,t);
	printf("%.8f %.8f\n",t.x,t.y);
	kock(n-1,t,p2);
}
int main(){
	int n;
	std::cin>>n;
	struct Point p1,p2;
	p1.x=0.0; p1.y=0.0;
	printf("%.8f %.8f\n",p1.x,p1.y);
	p2.x=100.0; p2.y=0.0;
	kock(n,p1,p2);
	printf("%.8f %.8f\n",p2.x,p2.y);
	return 0;
}
