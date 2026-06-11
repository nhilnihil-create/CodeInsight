#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;
struct Point{
	double x;
	double y;
};

void kock(int n,Point left,Point right){
	if(n==0) return;
	double PI=atan(1)*4;
	Point s={(2*left.x+right.x)/3,(2*left.y+right.y)/3};
	Point t={(left.x+2*right.x)/3,(left.y+2*right.y)/3};
	Point u={(t.x-s.x)*cos(PI/3)-(t.y-s.y)*sin(PI/3)+s.x,(t.x-s.x)*sin(PI/3)+(t.y-s.y)*cos(PI/3)+s.y};
	kock(n-1,left,s);
	cout<<fixed<<setprecision(5)<<s.x<<' '<<s.y<<'\n';
	kock(n-1,s,u);
	cout<<fixed<<setprecision(5)<<u.x<<' '<<u.y<<'\n';
	kock(n-1,u,t);
	cout<<fixed<<setprecision(5)<<t.x<<' '<<t.y<<'\n';
	kock(n-1,t,right);
}

int main(){
	int n;
	cin>>n;
	Point left={0,0},right={100,0};
	cout<<fixed<<setprecision(5)<<left.x<<' '<<left.y<<'\n';
	kock(n,left,right);
	cout<<fixed<<setprecision(5)<<right.x<<' '<<right.y<<'\n';
	return 0;
}
