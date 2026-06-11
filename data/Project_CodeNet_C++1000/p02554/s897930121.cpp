#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n;
ll ten,nine,eight;
int main()
{
	cin>>n;
	ten=1,nine=1,eight=1;
	for (int i=1;i<=n;i++) ten=ten*10%mod,nine=nine*9%mod,eight=eight*8%mod;
	ll ans=ten+mod-nine+mod-nine+mod+eight;
	cout<<ans%mod<<endl;
	return 0;
}

