#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL MOD = 998244353;
const int N = 3000;
LL memo[N+1][N+1];
LL mod_pow(LL base, LL exp)
{
	if(exp==0) return 1;
	if(exp&1) return (base*mod_pow(base,exp-1))%MOD;
	else return mod_pow((base*base)%MOD, exp>>1);
}
int n;
int a[N];
LL count(int i, int W)
{
	if(W < 0)
		return 0;
	if(W==0)
		return mod_pow(2,n-i);
	if(n==i) // and W > 0
		return 0;
	if(memo[i][W]!=-1)
		return memo[i][W];
	else
		return memo[i][W] = (count(i+1,W-a[i])+2*count(i+1,W))%MOD;
}
int main()
{
	int s; cin >> n >> s;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	memset(memo,-1,sizeof memo);
	cout<<count(0,s)<<endl;

	return 0;
}