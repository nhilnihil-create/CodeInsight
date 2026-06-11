#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=2e5+200;
struct node{
	int x,y;
}a[maxn];
bool mp1(node m,node w){
	return m.x+m.y<w.x+w.y;
}
bool mp2(node m,node w){
	return m.x-m.y<w.x-w.y;
}
bool mp3(node m,node w){
	return m.y-m.x<w.y-w.x;
}
int main(){
	int n,xi,yi;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d %d",&a[i].x,&a[i].y);
	}
	sort(a+0,a+n,mp1);
	int max1=abs(a[n-1].x-a[0].x)+abs(a[n-1].y-a[0].y);
	sort(a+0,a+n,mp2);
	int max2=abs(a[n-1].x-a[0].x)+abs(a[n-1].y-a[0].y);
	sort(a+0,a+n,mp3);
	int max3=abs(a[n-1].y-a[0].y)+abs(a[n-1].x-a[0].x);
	cout<<max(max1,max(max2,max3))<<endl;
	return 0;
}