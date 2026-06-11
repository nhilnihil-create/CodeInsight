#include <bits/stdc++.h>

#ifdef NON_SUBMIT
#define TEST(n) (n)
#define tout cerr
#else
#define TEST(n) ((void)0)
#define tout cin
#endif

using namespace std;

const int MOD=1e9+7;
int M[100001], D[100001];

int mul(int a, int b)
{
	return 1LL*a*b%MOD;
}

int fast_pow(int a, int b)
{
	int ret=1;
	for(;b;b>>=1) {
		if(b&1) ret=mul(ret,a);
		a=mul(a,a);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	TEST(freopen("input.txt","r",stdin));
	TEST(freopen("output.txt","w",stdout));
	TEST(freopen("debug.txt","w",stderr));
	int N, K, ans=0;
	cin>>N>>K; memset(M,-1,sizeof(M));
	for(int i=K;i>0;i--) {
		if(M[K/i]==-1) M[K/i]=fast_pow(K/i,N);
		D[i]=M[K/i];
		for(int j=2*i;j<=K;j+=i) {
			D[i]-=D[j];
			if(D[i]<0) D[i]+=MOD;
		}
		ans+=mul(i,D[i]);
		if(ans>=MOD) ans-=MOD;
	}
	cout<<ans<<'\n';
	return 0;
}