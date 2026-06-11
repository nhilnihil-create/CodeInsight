#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 110;
typedef double db;
int n;
db ans; 
struct vec{
	db x,y;
}v[N];
bool cmp(vec a,vec b){
	db A=atan2(a.y, a.x);
	db B=atan2(b.y, b.x);
	if(A!=B){
		return A<B;
	}
	return a.x<b.x;
}
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%lf %lf",&v[i].x,&v[i].y); 
	}
	sort(v+1, v+1+n, cmp);
	for(int i=n+1; i<=2*n; i++){
		v[i]=v[i-n];
	}
	for(int i=1; i<=n; i++){
		db x=0,y=0;
		for(int j=i; j<=i+n-1; j++){
			x+=v[j].x;
			y+=v[j].y;
			ans=max(ans, x*x+y*y);
		}
	} 
	printf("%.15lf\n",sqrt(ans));
	return 0;
}
