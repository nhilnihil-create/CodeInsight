#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    ll num;
    cin>>num;
    ll ans=num+1;
    for(ll i=1; i*i<=num; i++){
    	if(num%i==0){
    		ans=min(ans,i+num/i);
		}
	}
	cout<<ans-2;
	return 0;
}