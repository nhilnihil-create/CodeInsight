#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Maxn = 1000005;
ll a[Maxn];
ll p = 2;
ll qpow(ll y,int z,int p){
    y%=p;ll ans=1;
    for(int i=z;i;i>>=1,y=y*y%p)if(i&1)ans=ans*y%p;
    return ans;
}
ll C(ll n,ll m){
    if(m>n)return 0;
    return ((a[n]*qpow(a[m],p-2,p))%p*qpow(a[n-m],p-2,p)%p);
}
ll Lucas(ll n,ll m){
    if(!m)return 1;
    return C(n%p,m%p)*Lucas(n/p,m/p)%p;
}

ll N;
ll b[Maxn];
ll ans;
int main()
{
	a[1] =a[0] =  1;
	for(int i=2;i<Maxn;i++)	a[i] = (a[i-1] * i)%p;
	cin>>N;
	for(int i=1;i<=N;i++) scanf("%1lld",&b[i]);
	for(int i=1;i<N;i++) b[i] = abs(b[i] - b[i+1]);
	N--;
	bool HaveOne = false;
	for(int i=1;i<=N&&!HaveOne;i++) if(b[i] == 1) HaveOne = true;
	if(!HaveOne)	for(int i=1;i<=N;i++) b[i]/=2;
	for(int i=1;i<=N;i++)
	{
		ans += Lucas(N-1,i-1) * b[i];
		ans %= 2;
	}
	if(!HaveOne) ans *=2;
	cout<<ans;
	return 0;
}//奥里给