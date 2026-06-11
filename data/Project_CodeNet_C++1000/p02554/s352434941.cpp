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
#pragma GCC optimize(2)
using namespace std;
LL n,sum,k=1e9+7;
LL powr(LL x,LL y)
{
	if(y==0) return 1;
    if(y==1) return x%k;
    LL res=powr(x,y>>1);
    res=res*res%k;
    if(y%2==1) res=res*x%k; 
    return res%k;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	sum=(powr(10,n)-2*powr(9,n)%k+powr(8,n)+k)%k;
	cout<<sum;
	return 0;
}
/*
*/
