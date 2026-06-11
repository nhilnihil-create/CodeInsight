#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 606
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

int n,m;
int ans[maxn][maxn];

inline int read(){
    int x=0,f=1; char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x*f;
}

int main(){
	n=read(); int pps=1;
	for (int x=1;x<n;x<<=1,++pps){
		for (int i=x+1;i<=(x<<1);i++)
			for (int j=i+1;j<=(x<<1);j++)
				ans[i][j]=ans[i-x][j-x];
		for (int i=1;i<=x;i++)
			for (int j=x+1;j<=(x<<1);j++)
				ans[i][j]=pps;
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++)
			printf("%d ",ans[i][j]);
		puts("");
	}
    return 0;
}
