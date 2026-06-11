#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<int(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=100005;
ll f[N],g[N],n,ans,r,p;

int main(){
	read(n);
	f[0]=1;
	rep(i,0,n){
		read(r);
		while(p<=i&&r){
			if(f[p]>r){
				f[p]-=r;
				g[p+1]+=r;
				g[i+1]-=r;
				ans+=r*(i-p+1);
				r=0;
			}
			else{
				r-=f[p];
				g[p+1]+=f[p];
				g[i+1]-=f[p];
				ans+=f[p]*(i-p+1);
				f[p]=0;
				p++;
				g[p]+=g[p-1];
				f[p]=g[p];
			}
		}
		if(r){
			puts("-1");
			return 0;
		}
	}
	cout<<ans<<endl;
	return 0;
}
