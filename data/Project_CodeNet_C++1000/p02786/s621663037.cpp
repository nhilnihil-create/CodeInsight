#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp(ll var)
{
	if(var==1)
	 return 1;
	return 1+2*dp(var/2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    ll num;
    cin>>num;
    ll ans=dp(num);
    cout<<ans;
    return 0;
}