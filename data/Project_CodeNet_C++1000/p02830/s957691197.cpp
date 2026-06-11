
#include <bits/stdc++.h>
using namespace std;


#define M 1000000007
#define pb push_back
#define mp make_pair
#define s second
#define f first
#define mod 998244353
#define sz(v) (int)(v).size()

#define pii pair<int, int>
#define vi vector<int>
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)

ll add(ll a,ll b)
{
	a%=M;
	b%=M;
	ll p = (a+b)%M;
	return (p+M)%M;
}

ll mul(ll a,ll b)
{
	a%=M;
	b%=M;
	ll p = (a*b)%M;
	return (p+M)%M;
}


int main()
{
	fastio;
	ll i,n;
	string str1,str2,ans="";
	cin>>n;
	cin>>str1>>str2;
	for(i=0;i<n;i++)
	{
		ans+=str1[i];
		ans+=str2[i];
	}
	cout<<ans<<endl;
    return 0;
}



