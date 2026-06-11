#include<cstdio>
const int N=1000006;

int n,a[N],sum[N];
char s[N];
bool one=false;
bool odd=false;
bool two=false;

inline int Abs(int x) {
	return x<0?-x:x;
}
bool C2(int n,int m) {
	return sum[n]-sum[m]-sum[n-m];
}
int main() {
	scanf("%d",&n); n--;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) {
		a[i]=Abs(s[i]-s[i+1]);
		if(!(i&1)) sum[i]=sum[i>>1]+1;
	}
	for(int i=1;i<=n;i++)
		sum[i]+=sum[i-1];
	for(int i=1;i<=n;i++) {
		if((a[i]&1)) {
			if(!C2(n-1,i-1))
				odd=!odd;
			one=true;
		} else if(a[i]==2)
			if(!C2(n-1,i-1))
				two=!two;
	}
	if(odd) puts("1");
	else if(one||!two) puts("0");
	else puts("2");
	return 0;
}