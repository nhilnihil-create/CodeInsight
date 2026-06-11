#include<bits/stdc++.h>
using namespace std;
double mn,mx;
struct num{int A,B;}a[1000009];
bool cmp1(const num&a,const num&b){return a.A<b.A;}
bool cmp2(const num&a,const num&b){return a.B<b.B;}
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].A,&a[i].B);
	sort(a+1,a+n+1,cmp1); mn=(a[(n+1)/2].A+a[(n+2)/2].A)/2.;
	sort(a+1,a+n+1,cmp2); mx=(a[(n+1)/2].B+a[(n+2)/2].B)/2.;
	if(n&1) printf("%d",(int)(mx-mn+1));
	else printf("%d",(int)(2*(mx-mn+0.5)));
	return 0;
}