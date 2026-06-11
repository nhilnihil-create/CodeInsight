#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define kill _z_kill
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
#define User_Time ((double)clock()/CLOCKS_PER_SEC)
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned uint;
typedef long double LD;
typedef vector <int> vi;
typedef pair <int,int> pii;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
//int Pow(int x,int y){
//	int ans=1;
//	for (;y;y>>=1,x=(LL)x*x%mod)
//		if (y&1)
//			ans=(LL)ans*x%mod;
//	return ans;
//}
//void Add(int &x,int y){
//	if ((x+=y)>=mod)
//		x-=mod;
//}
//void Del(int &x,int y){
//	if ((x-=y)<0)
//		x+=mod;
//}
//int Add(int x){
//	return x>=mod?x-mod:x;
//}
//int Del(int x){
//	return x<0?x+mod:x;
//}
//void ckmax(int &x,int y){
//	if (x<y)
//		x=y;
//}
//void ckmin(int &x,int y){
//	if (x>y)
//		x=y;
//}
const int N=100005;
int n,m,v,p;
LL a[N],b[N];
int check(int k){
	For(i,1,n)
		b[i]=a[i];
	int cnt=v-1-(n-k);
	if (cnt>0){
		LL tot=(LL)cnt*m;
		For(i,1,k-1){
			if (b[i]>a[k]+m)
				continue;
			LL d=max(0LL,a[k]+m-b[i]);
			tot-=d;
			b[i]+=d;
		}
		For(i,1,k-1){
			LL d=min(a[i]+m-b[i],tot);
			tot-=d;
			b[i]+=d;
		}
	}
	int c=p;
	For(i,1,k-1)
		if (b[i]>a[k]+m)
			c--;
	return c>0;
}
int main(){
	n=read(),m=read(),v=read(),p=read();
	For(i,1,n)
		a[i]=read();
	sort(a+1,a+n+1,greater <int>());
	int ans=p,L=p+1,R=n;
	while (L<=R){
		int mid=(L+R)>>1;
		if (check(mid))
			L=mid+1,ans=mid;
		else
			R=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}