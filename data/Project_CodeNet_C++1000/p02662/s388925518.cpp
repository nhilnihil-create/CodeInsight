#include<bits/stdc++.h>
using namespace std;

#define ran 3033

struct modular_arithmetic{
	int mod;

	modular_arithmetic(){
		mod = 998244353;
	}
	//No specific settings.
	int add(int x,int y){return (x+=y)<mod?x:x-mod;}
	int sub(int x,int y){return (x-=y)>=0?x:x+mod;}
	int mul(int x,int y){return (int)((long long int)x*y%mod);}
	int pw(int base, int p) {
		int res = 1, mu = base%mod;
		for(;p>0;p/=2) {
			if (p&1) res = mul(res, mu);
			mu = mul(mu, mu);
		}
		return res;
	}
	int rev(int x) {return pw(x, mod-2);}
};
modular_arithmetic ma;

int n, s;
int a[ran];
int f[ran];

int main() {
	scanf("%d%d", &n, &s);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	
	memset(f, 0, sizeof f);
	f[0] = ma.pw(2, n);
	int rev2 = ma.rev(2);
	
	for(int i=1;i<=n;i++)
	for(int j=s;j>=a[i];j--)
		f[j] = ma.add(f[j], ma.mul(f[j-a[i]], rev2));
	printf("%d\n", f[s]);
	
	return 0;
}