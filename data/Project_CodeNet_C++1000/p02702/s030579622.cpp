#include<bits/stdc++.h>
#define pb push_back
#define sz(v) (v).size()
#define mod 2019
using namespace std;
typedef long long ll;

int num,p=1,cnt[2025];
string s;
ll ans;

int main()
{
	cin>>s;
	for(int i=sz(s)-1;i>=0;i--)
	{
		num+=(s[i]-'0')*p;
		num%=mod;
		p*=10;
		p%=mod;
		cnt[num]++;
	}
	for(int i=0;i<mod;i++)
		ans+=ll(cnt[i])*ll(cnt[i]-1);
	cout<<ans/2+cnt[0]<<endl;
	return 0;
}