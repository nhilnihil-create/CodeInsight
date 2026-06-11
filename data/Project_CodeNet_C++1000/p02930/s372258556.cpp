// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1 << 30, maxn=250005;

int n;

int f(int x,int y){
	-- x; -- y;
	for(int i=0;i<=30;i++)
		if((x>>i&1) != (y>>i&1))return i+1;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++)
			printf("%d ",f(i,j));
		puts("");
	}

	return 0;
}
