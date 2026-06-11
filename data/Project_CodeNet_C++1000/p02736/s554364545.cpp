#include<set>    
#include<map>    
#include<stack>    
#include<ctime>    
#include<cstdio>    
#include<queue>    
#include<cmath>    
#include<vector>    
#include<cstring>   
#include<climits>    
#include<iostream>   
#include<algorithm>
using namespace std;
#define LL long long
int read(){
    int f=1,x=0;char c=getchar();
    while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();}
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
    return f*x;
}
#define MAXN 1000000
#define INF 0x3f3f3f3f
char S[MAXN+5];
int a[MAXN+5],f2[MAXN+5];
int C(int n,int m){return f2[n]-f2[m]-f2[n-m]?0:1;}
int main(){
	int n=read();
	scanf("%s",S+1);
	for(int i=1;i<n;i++)
		a[i]=abs(S[i]-S[i+1]);
	int bei=2;
	for(int i=1;i<=n;i++)
		if(a[i]==1){
			bei/=2;
			break;
		}
	n--;
	for(int i=1;i<=n;i++)
		f2[i]=f2[i-1]+(int)log2(i&-i);
	if(bei==2)
		for(int i=1;i<=n;i++)
			a[i]>>=1;
	int ans=0;
	for(int i=1;i<=n;i++)
		if(a[i]==1)
			ans^=C(n-1,i-1);
	printf("%d\n",ans*bei);
	return 0;
}
