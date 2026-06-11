#include<bits/stdc++.h>
#define pf printf
#define sc(x) scanf("%d",&x);
#define scs(x) scanf("%s",x);
#define scl(x) scanf("%lld",&x);
#define rep(i,s,e) for(int i=s; i<=e; ++i)
#define dep(i,s,e) for(int i=s; i>=e; --i)
typedef long long ll;
using namespace std;
const int Max=2e5+5;
int a[Max],b[Max];
int main()
{
	int n;
	sc(n);
	for(int i=1;i<=n;i++){
		sc(a[i]);sc(b[i]);
	}sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	if(n%2==1){
		pf("%d\n",b[n/2+1]-a[n/2+1]+1);
	}else{
		pf("%d\n",(int)((1.0*(b[n/2+1]+b[n/2])/2-1.0*(a[n/2+1]+a[n/2])/2)*2+0.5)+1);
	} 
}
