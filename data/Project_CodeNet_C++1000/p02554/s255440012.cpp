#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;

const int maxn = 100010;
const int M = 1000000007;

int n;
ll a1,a2,a3,a4;

ll ksm(ll i,ll po){
	ll res = 1ll;
	while(po){
		if(po & 1) res = res * i % M;
		po >>= 1;
		i = i * i % M;
	}
	return res % M; 
}

ll read(){ ll s=0,f=1; char ch=getchar(); while(ch<'0' || ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } while(ch>='0' && ch<='9'){ s=s*10+ch-'0'; ch=getchar(); } return s*f; }

int main(){
	a1 = 0 , a2 = 0, a3 = 0, a4 = 0;
	n = read();
	ll a1 = ksm(10,n);
	ll a2 = ksm(9,n);
	ll a3 = ksm(9,n);
	ll a4 = ksm(8,n);
	
	printf("%lld\n",(((a1-a2+M)%M-a3+M)%M+a4)%M);
	
	return 0;
}