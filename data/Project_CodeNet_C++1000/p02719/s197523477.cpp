#include<iostream>
#include<math.h>
#define LL long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(0)
using namespace std;

int main()
{
	LL n, k; cin>>n>>k;
	if(n%k==0) { cout<<0<<endl; return 0; }

	LL a=n%k, b=abs(k-a);
	if(a<b) cout<<a<<endl;
	else cout<<b<<endl;
}
