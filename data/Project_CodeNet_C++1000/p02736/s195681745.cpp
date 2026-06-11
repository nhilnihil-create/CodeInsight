#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#include <assert.h>
#include <bitset>
#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define quickcin ios_base::sync_with_stdio(false);
const int mod=1e9+7;
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
using namespace std;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
int n;
int a[1000005];

bool C(int a,int b)
{
	if(a<=1 && b<=1) return !(a==0 && b==1);
	return C(a/2,b/2) & C(a%2,b%2);
}

bool judge1()
{
	int s=0;
	for(int i=0;i<n;i++)
	{
		s+=a[i]*C(n-1,i);
	}
	return (s&1);
}

void deduce()
{
	n--;
	for(int i=0;i<n;i++)
	{
		a[i]=abs(a[i+1]-a[i]);
	}
}

bool judge2()
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==1) return false;
	}
	for(int i=0;i<n;i++)
	{
		a[i]/=2;
	}
	return judge1();
}

int getch()
{
	char c=0;
	while(!isdigit(c)) c=getchar();
	return c-'0';
}

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		a[i]=getch();
	}
	deduce();
	if(n==1)
	{
		over(a[0]);
	}
	if(judge1()) over("1");
	if(judge2()) over("2");
	puts("0");
	return 0;
}