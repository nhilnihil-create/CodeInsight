#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e5+10;

void io(){
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
}

struct node{
	double x;
	double y;
}p[N];

bool cmp(node a,node b)
{
	return atan2(a.x,a.y)>atan2(b.x,b.y);
} 
int main()
{
	//io();
	int n;cin>>n;
	for(int i=0;i<n;i++)	cin>>p[i].x>>p[i].y;
	sort(p,p+n,cmp);
	double ans=0;
	for(int i=0;i<n;i++){
		double a=0,b=0;
		int now=i;
		do{
			a+=p[now].x;
			b+=p[now].y;
			ans=max(ans,a*a+b*b);
			if(now+1<n)now++;
			else now=0;
		}while(now!=i);
	}
	printf("%.15f\n",sqrt(ans));
	return 0;
}