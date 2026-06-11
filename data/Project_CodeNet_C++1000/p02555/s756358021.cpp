#include<iostream>
#include<algorithm>
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0); 
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int maxn=2010;
ll a[maxn];
int S;

void cal()
{
	a[1]=0,a[2]=0;
	for(int i=3;i<=5;i++) a[i]=1;
	a[6]=2,a[7]=3;
	for(int i=8;i<=2000;i++) a[i]=(a[i-1]+a[i-3])%MOD;
}



int main()
{
	ios;
	cal();
	cin>>S;
	cout<<(a[S]+MOD)%MOD<<"\n";
	return 0;
}
