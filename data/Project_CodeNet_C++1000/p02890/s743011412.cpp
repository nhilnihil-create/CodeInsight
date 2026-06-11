#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
using namespace std;
int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
    return xx*ff;
}
long long READ(){
    long long xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
    return xx*ff;
}
char one(){
	char ch=getchar();
	while(ch==' '||ch=='\n')
		ch=getchar();
	return ch;
}
const int maxn=300010;
int N,a[maxn],b[maxn],c[maxn],d[maxn],e[maxn];
int main(){
	//freopen("in","r",stdin);
	N=read();
	for(int i=1;i<=N;i++)
		a[read()]++;
	for(int i=1;i<maxn;i++)
		b[a[i]]++;//b:occur times
	for(int i=1;i<=N;i++){
		c[i]=c[i-1]+b[i]*i;//c:sum of occur times <= i
		d[i]=d[i-1]+b[i];//d:prefix sum
	}
	for(int i=1;i<=N;i++)
		e[i]=c[i]/i+d[N]-d[i];
	for(int i=1,j=N;i<=N;i++){
		for(;j;j--)
			if(e[j]>=i){
				printf("%d\n",j);
				break;
			}
		if(!j)
			printf("%d\n",j);
	}
	return 0;
}
