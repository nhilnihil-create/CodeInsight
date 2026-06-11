#include<bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define rloop(i,a,b) for(j=a;j>=b;j--)
#define vi vector<int>
#define pi 3.14159265358979323846
using namespace std;

void koch(int n, pair<double,double> a, pair<double,double> b);
int main(){
	int n,i,j;
	cin>>n;
	pair<double,double> a(0,0),b(100,0);
	printf("%.8lf %.8lf\n",a.first,a.second);
	koch(n,a,b);
	printf("%.8lf %.8lf\n",b.first,b.second);
}

void koch(int n, pair<double,double> a, pair<double,double> b){
	if(n==0){
		return;
	}
	double th=pi/3.0;
	pair<double,double> s((2*a.first+b.first)/3.0,(2*a.second+b.second)/3.0);
	pair<double,double> t((a.first+2*b.first)/3.0,(a.second+2*b.second)/3.0);
	pair<double,double> u((t.first-s.first)*cos(th)-(t.second-s.second)*sin(th)+s.first,(t.first-s.first)*sin(th)+(t.second-s.second)*cos(th)+s.second);
	koch(n-1,a,s);
	printf("%.8lf %.8lf\n",s.first,s.second);
	koch(n-1,s,u);
	printf("%.8lf %.8lf\n",u.first,u.second);
	koch(n-1,u,t);
	printf("%.8lf %.8lf\n",t.first,t.second);
	koch(n-1,t,b);
}