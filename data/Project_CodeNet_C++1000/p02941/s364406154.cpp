#include<bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define uniq(x) (x).erase(unique(ALL(x)),(x).end())
#define SORT(x) sort(ALL(x))
#define REV(x) reverse(ALL(x))
#define foreach(it,x) for(__typeof((x).begin()) it=(x).begin();it!=(x).end();it++)
#define debug(x) cerr<<#x<<"="<<(x)<<endl
#define gett() cerr<<"Time:"<<clock()<<"ms."<<endl
#define ri(x) scanf("%d",&x)
#define rl(x) scanf("%lld",&x)
#define rlcfpoj(x) scanf("%I64d",&x)
#define pi(x) printf("%d",x)
#define pl(x) printf("%lld",x)
#define plcfpoj(x) printf("%I64d",x)
#define lfd() printf("\n")
#define sp() printf(" ")
#define inrep(x) int x;scanf("%d",&x);while(x--)
#define testbit(mask,i) (((mask)>>(i))&1)
#define setbit(mask,i) ((mask)|(1<<i))
#define delbit(mask,i) ((mask)^(1<<i))
int n;
int a[200100],b[200100];
int l[200100],r[200100];
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++){
		if(a[i]>b[i]){
			cout<<-1<<endl;
			return 0;
		}
	}
	for(int i=2;i<=n;i++)
		l[i]=i-1;
	l[1]=n;
	for(int j=1;j<n;j++)
		r[j]=j+1;
	r[n]=1;
	long long res=0LL;
	int cnt=0;
	while(1){
		bool ok=true,chg=false;
		for(int i=1;i<=n;i++){
			if(b[i]==a[i])
				continue;
			if(b[i]<a[i]){
				cout<<-1<<endl;
				return 0;
			}
			ok=false;
			long long he=(long long)(b[l[i]]+b[r[i]]);
			if(b[i]-he<a[i])
				continue;
			res+=(long long)((b[i]-a[i])/he);
			b[i]-=((b[i]-a[i])/he)*he;
			chg=true;
		}
		if(ok)
			break;
		if(!chg){
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<res<<endl;
	return 0;
}
