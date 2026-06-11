#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORL(i,x) for(int i=head[x];i;i=nxt[i])
#define clr(x,y) memset(x,y,sizeof(x))
#define in(a) a=read()
#define out(a) printf("%d\n",a)
inline ll read(){
    char c=getchar();ll f=1,x=0;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
    return x*f;
}
#define mod 989381
#define maxn 500010
#define inf (1<<30)
int a[maxn],b[maxn];
ll s1[maxn],s2[maxn];
int main(){
	int n;
	in(n);
	FOR(i,1,n)a[read()]++;
	int num=0;
	FOR(i,1,n)
		if(a[i])
			b[++num]=a[i];
	sort(b+1,b+num+1);	
	FOR(i,1,num){
		s1[b[i]]++;
		s2[b[i]]+=b[i];	
	}
	FORD(i,n,1)s1[i]+=s1[i+1];
	FOR(i,1,n)s2[i]+=s2[i-1];
	int ans=n;
	FOR(i,1,n){
		while(1){
			int x=s1[ans];
			if(s2[ans-1]>=1ll*ans*(i-x))break;
			else ans--;
		}
		out(ans);
	}
}
//sum>=(c-x)*s