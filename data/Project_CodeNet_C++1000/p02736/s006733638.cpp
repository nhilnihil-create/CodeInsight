#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n,a[1000005],fac[1000025],p;

inline int power(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % p;
		a = a * a % p, b >>= 1;
	}
	return res;
}

inline int C(int n, int m) {
	if (m > n) return 0;
	return fac[n] * power(fac[m], p - 2) % p *  power(fac[n - m], p - 2) % p;
}

inline int Lucas(int n, int m) {
	if (!m) return 1;
	return C(n % p, m % p) * Lucas(n / p, m / p) % p;
}
inline void init() {
	int maxn = p;
	fac[0] = 1;
	for (int i = 1; i <= maxn; i++) fac[i] = fac[i - 1] * i % p;
}


int main()
{
    scanf("%d\n",&n);
    if(n==1)
    {
        printf("%d\n",getchar()-'0');
        return 0;
    }
    char now;
    bool oex = false;int cc = 1;
    for(int i=0;i<n;++i){
        a[i] = getchar()-'0';
        a[i]-=1;
        if(a[i]==1) oex = true;
    }
    int ocnt =0;n-=1;
    int tcnt = 0;p=2;

    for(int i=0;i<=n;++i)
    {
        init();
        if(a[i]==1){
            ocnt += (Lucas(n,i) +2);
            ocnt %= 2;
        }
        if(a[i]==2){
            tcnt += (Lucas(n,i) +2);
            tcnt %= 2;
        }
    }

    if(ocnt) {
        printf("1\n");return 0;
    }

    if(oex) {
        printf("0\n");return 0;
    }

    if(tcnt) printf("2\n");
    else printf("0\n");

    return 0;
}
