
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
	ll i,j,k,x,y,a,b,c;
	ll p[100010],q[100010],r[100010];
	cin>>x>>y>>a>>b>>c;
	for(i=0;i<a;i++)
		cin>>p[i];
	for(i=0;i<b;i++)
		cin>>q[i];
	for(i=0;i<c;i++)
		cin>>r[i];
	sort(p,p+a);
	sort(q,q+b);
	sort(r,r+c);
	// ll sum=0;
	// set<ll> S;
	// for(i=a-1;i>a-1-x && i>=0;i--)
	// {
	// 	S.insert(p[i]);
	// 	sum += p[i];
	// }
	// for(j=b-1; j>b-1-y && j>=0;j--)
	// {
	// 	S.insert(q[j]);
	// 	sum += q[j];
	// }
	// for(i=c-1;i>=0;i--)
	// {
	// 	ll val = *S.begin();
	// 	if(val<r[i])
	// 	{
	// 		sum+=r[i]-val;
	// 		S.erase(S.begin());
	// 		// S.insert(r[i]);
	// 	}
	// }
	ll sum=0;
	vector<ll> v;
	for(i=a-1;i>a-1-x && i>=0;i--)
		v.pb(p[i]);
	for(j=b-1;j>b-1-y && j>=0;j--)
		v.pb(q[j]);
	for(i=0;i<c;i++)
		v.pb(r[i]);
	sort(v.begin(),v.end());
	ll cnt=0;
	for(i=sz(v)-1;i>=0;i--)
	{
		sum+=v[i];
		cnt++;
		if(cnt==x+y)
			break;
	}
	cout<<sum<<endl;
    return 0;
}



