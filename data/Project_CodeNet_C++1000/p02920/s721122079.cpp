#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<set>
#define ll long long
#define maxn 300010
inline ll read()
{
	ll x=0; char c=getchar(),f=1;
	for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
inline void write(ll x)
{
	static int buf[20],len; len=0;
	if(x<0)x=-x,putchar('-');
	for(;x;x/=10)buf[len++]=x%10;
	if(!len)putchar('0');
	else while(len)putchar(buf[--len]+'0');
}
inline void writeln(ll x){write(x); putchar('\n');}
inline void writesp(ll x){write(x); putchar(' ');}
std::multiset<int>st;
int a[maxn],b[maxn];
int n;
int main()
{
	n=read();
	int mx=0;
	for(int i=1;i<=1<<n;i++){
		a[i]=read();
		mx=std::max(mx,a[i]);
		st.insert(a[i]);
	}
	b[1]=mx; st.erase(st.lower_bound(mx));
	for(int k=1;k<1<<n;k<<=1)
		for(int i=k+1;i<=(k<<1);i++){
			auto iter=st.lower_bound(b[i-k]);
//			printf("%d %d %d %d\n",i,k,*iter,b[i-k]);
			if(iter==st.begin()){
				puts("No"); return 0;
			}
			b[i]=*(--iter); st.erase(iter);
		}
	puts("Yes");
//	for(int i=1;i<=1<<n;i++)
//		printf("%d %d\n",i,b[i]);
	return 0;
}