#pragma GCC optimize("Ofast","inline")
#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define next Next
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
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
const int N=100010*2;
int n,m,r;
vector <pair <int,int> > ans;
int vis[N];
int main(){
	n=read();
	if (n<=2)
		return puts("No"),0;
	m=n/4-1;
	r=n%4;
	ans.pb(mp(1,2));
	ans.pb(mp(2,3));
	ans.pb(mp(3,n+1));
	ans.pb(mp(n+1,n+2));
	ans.pb(mp(n+2,n+3));
	For(i,1,m){
		ans.pb(mp(i*4,i*4+1));
		ans.pb(mp(i*4+1,i*4+2));
		ans.pb(mp(i*4+2,i*4+3));
		ans.pb(mp(i*4+3,n+i*4));
		ans.pb(mp(n+i*4,n+i*4+1));
		ans.pb(mp(n+i*4+1,n+i*4+2));
		ans.pb(mp(n+i*4+2,n+i*4+3));
	}
	if (n>3){
		int t=4*(m+1);
		if (r==0){
			vector <int> id;
			For(i,2,20)
				if (n>>i&1)
					id.pb(1<<i);
			sort(id.begin(),id.end());
			if (id.back()>=n)
				return puts("No"),0;
			For(i,1,(int)id.size()-1){
				vis[id[i]]=1;
				ans.pb(mp(id[i],id[i-1]));
			}
			For(i,1,m)
				if (!vis[i*4])
					ans.pb(mp(i*4,1));
			ans.pb(mp(id[0],n+n));
			ans.pb(mp(id.back(),n));
		}
		else if (r==1){
			For(i,1,m)
				ans.pb(mp(i*4,1));
			ans.pb(mp(t,t+1));
			ans.pb(mp(t+1,1));
			ans.pb(mp(1,n+t));
			ans.pb(mp(n+t,n+t+1));
		}
		else if (r==2){
			For(i,1,m)
				ans.pb(mp(i*4,1));
			ans.pb(mp(t,t+1));
			ans.pb(mp(t+1,1));
			ans.pb(mp(1,n+t));
			ans.pb(mp(n+t,n+t+1));
			ans.pb(mp(t+2,t+1));
			ans.pb(mp(2,n+t+2));
		}
		else {
			For(i,1,m)
				ans.pb(mp(i*4,1));
			ans.pb(mp(t,t+1));
			ans.pb(mp(t+1,1));
			ans.pb(mp(1,n+t));
			ans.pb(mp(n+t,n+t+1));
			ans.pb(mp(t+2,t+1));
			ans.pb(mp(2,n+t+2));
			ans.pb(mp(t+3,n+t+2));
			ans.pb(mp(3,n+t+3));
		}
	}
	puts("Yes");
	for (auto p : ans)
		printf("%d %d\n",p.fi,p.se);
	return 0;
}