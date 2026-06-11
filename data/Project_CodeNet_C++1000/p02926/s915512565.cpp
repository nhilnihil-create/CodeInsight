#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
struct node{
	double x,y;
}p[105];
bool cmp(node a,node b){
	RE atan2(a.x,a.y)<atan2(b.x,b.y);
}
int n;
int main(){
	scanf("%d",&n);
	FOR(i,1,n)scanf("%lf%lf",&p[i].x,&p[i].y);
	sort(p+1,p+n+1,cmp);
	int l;
	double tx,ty,ans=0;
	FOR(i,1,n){
		tx=p[i].x;ty=p[i].y;l=i;
		ans=max(ans,tx*tx+ty*ty);
		rep(j,1,n){
			l++;
			if(l>n)l=1;
			tx+=p[l].x;ty+=p[l].y;
			ans=max(ans,tx*tx+ty*ty);
		}
	}
	printf("%.12f",sqrt(ans));
	RE 0;
}

