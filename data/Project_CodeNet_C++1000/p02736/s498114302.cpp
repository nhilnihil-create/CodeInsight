#include <bits/stdc++.h>
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
const int N=1e6+5;
int n;
int a[N];
int cnt(int n){
	if (n==0)
		return 0;
	int res=0;
	while (n%2==0)
		res++,n/=2;
	return res;
}
int main(){
	n=read();
	For(i,1,n)
		scanf("%1d",&a[i]),a[i]--;
//	outarr(a,1,n);
	int flag=0;
	For(i,1,n)
		if (a[i]==1)
			flag=1;
	if (flag)
		For(i,1,n)
			a[i]%=2;
	else
		For(i,1,n)
			a[i]/=2;
	int ans=0;
	int c=0;
	For(i,1,n){
		if (a[i])
			ans^=c==0;
		c+=cnt(n-i)-cnt(i);
	}
	if (!flag)
		ans*=2;
	cout<<ans<<endl;
	return 0;
}