//E
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef long long ll;

struct apple{
	int col,val;
}a[3*maxn];

bool cmp(apple p,apple q){ return p.val>q.val; }
	
int main()
{
	int x,y,A,B,C;
	scanf("%d%d%d%d%d",&x,&y,&A,&B,&C);
	for(int i=1;i<=A+B+C;i++){
		scanf("%d",&a[i].val);
		if(i<=A) a[i].col=1;
		else if(i<=A+B) a[i].col=2;
		else a[i].col=3;
	}
	sort(a+1,a+A+B+C+1,cmp);
	ll ans=0; int sum=0;
	for(int i=1;i<=A+B+C;i++){
		if(a[i].col==1&&x) {
			x--;ans+=(ll)a[i].val;
		}
		if(a[i].col==2&&y) {
			y--; ans+=(ll)a[i].val;	
		}
		if(a[i].col==3){
			ans+=(ll)a[i].val;
			sum++;
		}
//		cout<<a[i].val<<endl;
		if(sum==x+y)break;
	}
	printf("%lld\n",ans);
}