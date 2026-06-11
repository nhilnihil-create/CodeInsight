/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define loop(i,n) for(int i=0;i<(n);i++)
#define cont(i,n) for(int i=1;i<=(n);i++)
#define circ(i,a,b) for(int i=(a);i<=(b);i++)
#define range(i,a,b,c) for(int i=(a);((c)>0?i<=(b):i>=(b));i+=(c))
#define foreach(it,v) for(__typeof((v).begin()) it=(v).begin(),_e_D_=(v).end();it!=_e_D_;it++)
#define y0 y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1 y1II11II11III11I1III11II111IIII1II1I1
#define pub push_back
#define pob pop_back
#define mak make_pair

typedef long long ll;
typedef long double lf;
const int Inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

int k,q;
ll d[5005],h[5005];

int main(){
	scanf("%d%d",&k,&q);
	loop(i,k)scanf("%lld",d+i);
	while(q--){
		int n,x,m;scanf("%d%d%d",&n,&x,&m);
		n--;x%=m;h[0]=0;
		int circhv=0;
		loop(i,k)h[i+1]=h[i]+d[i]%m,circhv+=(d[i]%m>0);
		int cyc=n/k,rem=n%k;ll sms=x+cyc*h[k];
		ll res=cyc*circhv-sms/m;sms%=m;
		loop(i,rem){
			int nsms=(sms+d[i])%m;
			if(nsms>sms)res++;sms=nsms;
		}
		printf("%lld\n",res);
	}
	return 0;
}