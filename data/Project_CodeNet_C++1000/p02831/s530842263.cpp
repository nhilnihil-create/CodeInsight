#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fi first
#define sec second 
int main()
{	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
		ll n,m; cin>>n>>m;
		ll g=__gcd(n,m),b=(n*m);
		cout<<(b/g)<<endl;
	return 0;
}