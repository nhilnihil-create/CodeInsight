#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define ll long long
//{{{ read()
inline int read(){
	register int x=0,f=1;
	register char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')	x=x*10+(ch^48),ch=getchar();
	return x*f;
}
//}}}
const double Pi=acos(-1);
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int a=read(),b=read(),h=read(),m=read();
	double t1=1.0*(h*60+m)/(12*60)*Pi*2,t2=1.0*m/60*Pi*2;
	double x1=a*cos(t1),y1=a*sin(t1),x2=b*cos(t2),y2=b*sin(t2);
	printf("%.10lf\n",sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
	return 0;
}
