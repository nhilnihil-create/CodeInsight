#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cctype>
#define LL long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int N = 1e5 + 3;
int a[N],b[N],x[N],y[N],c[N];
int A,B,M;
int main(){
	scanf("%d%d%d",&A,&B,&M);
	for(int i = 1;i <= A;++i) scanf("%d",&a[i]);
	for(int i = 1;i <= B;++i) scanf("%d",&b[i]);
	for(int i = 1;i <= M;++i) scanf("%d%d%d",&x[i],&y[i],&c[i]);
	int ans = 0x3f3f3f3f;
	for(int i = 1;i <= M;++i) ans = min(ans,a[x[i]] + b[y[i]] - c[i]);
	sort(a + 1,a + A + 1);sort(b + 1,b + B + 1);
	printf("%d\n",min(ans,a[1] + b[1]));
	return 0;
}

