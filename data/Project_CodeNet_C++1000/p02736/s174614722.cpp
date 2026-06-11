#include<algorithm>
#include<iostream>
#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#define ll long long
using namespace std;
//{{{ read()
inline int read(){
	register int x=0,f=1;
	register char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	x=x*10+(ch^48);
	return x*f;
}
//}}}
const int N=1e6+5;
int n,a[N],b[N];
int C(int n,int m){
	if((n&m)==m)	return 1;
	return 0;
}
int work(){
	int res=0;
	for(int i=1;i<n;i++)
		if(b[i]&&C(n-2,i-1))	res^=1;
	return res;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	a[i]=read();
	for(int i=1;i<n;i++)	b[i]=(abs(a[i]-a[i+1]));
	int flag=0;
	for(int i=1;i<n;i++)
		if(b[i]==1)	flag=1;
	if(flag){
		for(int i=1;i<=n;i++)
			if(b[i]==2)	b[i]=0;
	}
	else{
		for(int i=1;i<=n;i++)
			if(b[i]==2)	b[i]=1;
	}
	int d=work();
	if(flag){
		if(d)	puts("1");
		else	puts("0");
	}
	else{
		if(d)	puts("2");
		else	puts("0");
	}
	return 0;
}