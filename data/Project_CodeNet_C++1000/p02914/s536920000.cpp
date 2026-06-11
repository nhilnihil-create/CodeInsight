#include<bits/stdc++.h>
#define For(a,b,c) for(int a=b;a<=c;++a)
#define Dor(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
using namespace std;
const int N=100007;
int n,C[60];
LL A[N],S[60];
void ins(LL x) {
	Dor(i,59,0)
	if(x&(1LL<<i)) {
		if(!S[i]) {
			S[i]=x;
			break;
		}
		x^=S[i];
	}
}
int main() {
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&A[i]);
	For(i,1,n)
		For(j,0,59)
		if((A[i]&1LL<<j)) ++C[j];
	For(i,1,n)
		For(j,0,59)
		if((A[i]&1LL<<j)&&C[j]&1) A[i]^=1LL<<j;
	For(i,1,n) ins(A[i]);
	LL ans=0;
	Dor(i,59,0) ans=max(ans,ans^S[i]);
	ans<<=1;
	For(i,0,59)
	if(C[i]&1) ans+=1LL<<i;
	printf("%lld",ans);
	return 0;
}
