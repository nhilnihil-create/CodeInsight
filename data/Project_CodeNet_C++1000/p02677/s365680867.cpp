#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+1;
const ll INF=1e10;
const double PI=acos(-1.0);

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	double a,b,h,m;
	cin>>a>>b>>h>>m;
	double th1=6*m*PI/180,th2=(60*h+m)/2*PI/180;
	double x=pow(b*cos(th1)-a*cos(th2),2),y=pow(b*sin(th1)-a*sin(th2),2),ans=sqrt(x+y);
	printf("%.9lf",ans);	
}
