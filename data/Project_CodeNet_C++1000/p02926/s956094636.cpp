#include<bits/stdc++.h>
#define V(u) (u.x>=0?(u.y>=0?1:4):(u.y>=0?2:3))
using namespace std;
struct point{
	double x,y;
}p[110];
int n,a[110],b[110];
double tx,ty,ans;
bool cmp(point x,point y){
	if(V(x)!=V(y))return V(x)<V(y);
	return x.x*y.y-x.y*y.x>0;
}
void Work(int t){
	if(t==1)for(int i=1;i<=n;++i)p[i].x=a[i],p[i].y=b[i];
	else if(t==2)for(int i=1;i<=n;++i)p[i].x=-b[i],p[i].y=a[i];
	else if(t==3)for(int i=1;i<=n;++i)p[i].x=-a[i],p[i].y=-b[i];
	else for(int i=1;i<=n;++i)p[i].x=b[i],p[i].y=-a[i];
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;++i){
		tx=ty=0;
		for(int j=i;j<=n;++j)tx+=p[j].x,ty+=p[j].y,ans=max(ans,sqrt(tx*tx+ty*ty));
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&a[i],&b[i]);
	Work(1),Work(2),Work(3),Work(4);
	printf("%.12lf",ans);
	return 0;
}