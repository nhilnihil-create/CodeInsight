#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 5005
int d[N],k,a[N];
void work()
{
	int n=read(),x=read(),m=read();
	x%=m; int sum=0;
	int ze=0;
	for(int i=1;i<=k;i++) a[i]=d[i]%m,sum+=a[i];
	for(int i=1;i<=k;i++) if(a[i]==0) ze++;
	int r=(n-1)/k;
	int ans=r*sum+x;
	ze*=r;
	for(int i=r*k+1;i<n;i++) ans+=a[i%k];
	for(int i=r*k+1;i<n;i++) if(a[i%k]==0) ze++;
//	cout<<ans<<endl;
	printf("%lld\n",n-ans/m-1-ze);
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int Q;
	cin>>k>>Q;
	for(int i=1;i<=k;i++) d[i]=read();
	while(Q--) work();
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}

