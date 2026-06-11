#include "bits/stdc++.h"
using namespace std;
#define MODULO 1000000007
#define PI 3.14159265359
typedef long long int ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll res=0;
	for(int c=1;c<n;++c)
	{
		res=res+(n-1)/c;
	}
	cout<<res<<endl;
    return 0;
}
