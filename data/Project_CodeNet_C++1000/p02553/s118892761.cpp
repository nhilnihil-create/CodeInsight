#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#define M 1010
#define N 1000000
#define D double
#define LL long long
using namespace std;
LL a,b,c,d,sum;
LL max(LL x,LL y)
{
	if(x>y) return x;
	else return y; 	
} 
LL maxx(LL x,LL y,LL z,LL k)
{
	LL ss=max(max(max(x,y),z),k);
	return ss;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin>>a>>b>>c>>d;
	sum=maxx(a*c,a*d,b*c,b*d);
	cout<<sum;
	return 0;
}
/*
*/
