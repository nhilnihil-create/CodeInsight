#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define pb push_back 
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
#define si(x) scanf("%d",&x)
#define sd(x) scanf("%lf",&x)
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int a[3]={300000,200000,100000};
int main(int argc, char** argv) {
	int x,y;
	si(x);
	si(y);
	int ans=0;
	if(x==1&&y==1)
	{
		ans+=400000;
	}
	rep(i,1,3)
	{
		if(x==i)ans+=a[i-1];
		if(y==i)ans+=a[i-1];
	}
	cout<<ans;
	return 0;
}