#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
map<int,int>xc,yc;
struct node{
	int x,y;
}p[N];
int numx,numy,cnt1,cnt2,cnt,h,w,m;
int main(){
	scanf("%d%d%d",&h,&w,&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		p[i]={x,y};
		xc[x]++;yc[y]++;
		numx=max(numx,xc[x]),numy=max(numy,yc[y]);
	}
	for(auto it=xc.begin();it!=xc.end();it++){
		int d=it->second;
		if(d==numx)cnt1++;
	}
	for(auto it=yc.begin();it!=yc.end();it++){
		int d=it->second;
		if(d==numy)cnt2++; 
	}
//	printf("%d %d\n",numx,numy);
	for(int i=1;i<=m;i++){
		if(xc[p[i].x]==numx&&yc[p[i].y]==numy)cnt++;
	}
//	printf("%d %d %d\n",cnt,cnt1,cnt2);
	if(cnt==cnt1*cnt2){
		printf("%d\n",numx+numy-1);
	}
	else printf("%d\n",numx+numy);
	return 0;
}
