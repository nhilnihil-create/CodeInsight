#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int main(){
	int x,y,a,b,c;
	cin >>x>>y>>a>>b>>c;
	int p[a+1],q[b+1],r[c+1];
	p[0]=0;
	q[0]=0;
	r[0]=0;
	rep(i,a)cin>>p[i+1];
	rep(i,b)cin>>q[i+1];
	rep(i,c)cin>>r[i+1];
	sort(p,p+a+1);
	sort(q,q+b+1);
	sort(r,r+c+1);
	int red=0,g=0,m=0;
	int color;//0赤1緑2無色
	int good;//良さ
	long long int sum=0;
	while(red+g+m<x+y)
	{	
		color=2;
		good=r[c-m];
		if(red<x&& p[a-red]>good){
			color=0;
			good=p[a-red];
		}
		if(g<y&& q[b-g]>good){
			color=1;
			good=q[b-g];
		}
		sum+=good;
		if(color==0)red++;
		if(color==1)g++;
		if(color==2)m++;
	}
	cout <<sum;
}