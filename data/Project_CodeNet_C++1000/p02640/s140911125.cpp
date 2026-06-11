#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
#include<map>
#include<set>
#define maxn 200005
#define lson (now<<1)
#define rson ((now<<1)|1)
#define mid ((nl+nr)>>1)
using namespace std;
typedef long long ll;
int main()
{
	int x,y;
	cin>>x>>y;
	if(y-2*x<0)
		printf("No\n");
	else if((y-2*x)&1)
		printf("No\n");
	else if((x-(y-2*x)/2)<0)
		printf("No\n");
	else
		printf("Yes\n");
}