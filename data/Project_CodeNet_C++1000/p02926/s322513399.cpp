#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;

struct point {
    double x,y;
}p[N];

bool cmp(point a,point b){
	return atan2(a.y,a.x)>atan2(b.y,b.x);
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%lf%lf",&p[i].x,&p[i].y);
    }
    sort(p,p+n,cmp);
    double ans = 0;
    for(int i=0;i<n;++i){
        double x = 0,y = 0;
        int j = i;
        do{
            x += p[j].x, y += p[j].y;
            ans = max(ans,x*x+y*y);
            j = (j+1)%n;
        }while(i!=j);
    }
    printf("%.15lf\n",sqrt(ans));
    return 0;
}