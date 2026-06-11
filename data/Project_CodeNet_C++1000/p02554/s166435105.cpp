#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
int powmod(int n,int m)
{
	int p=1;
	for(int i=1;i<=m;i++)
	p=p*n%MOD;
	return p;
}
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	if(n==2){
		cout<<2<<endl;
		return 0;
	}
	cout<<(powmod(10,n)+MOD-powmod(9,n)*2+MOD+powmod(8,n)+MOD)%MOD;
    return 0;
}
