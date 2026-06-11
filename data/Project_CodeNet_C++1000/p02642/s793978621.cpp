//Practice more and more
//learn for better
#define bn begin()
#define en end()
#define mx 1000010
#define pb push_back
#define PI (2.0*acos(0.0))
#define ALL(a) a.begin(),a.end()
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rep(a,b) for(int a=0;a<b;++a)
#define fastio ios::sync_with_stdio(false)
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int>  vi;
typedef vector<ll> vll;
int main()
{
ios::sync_with_stdio(false);
cin.tie(NULL);
	int a,b,n,i,j,t,tmp;
	cin>>n;
	vi v,v1(mx,0);
	for(i=0;i<n;i++)
	{
		cin>>a;
		v.pb(a);
	}
	sort(ALL(v));
	for(i=0;i<n;i++)
	{
		tmp=v[i];
		for(j=tmp;j<=v[n-1];j+=tmp)
		v1[j]++;
	}
	ll cnt=0;
	for(i=0;i<n;i++)
{
	// cout<<v[i]<<" "<<v1[v[i]]<<endl;
	if(v1[v[i]]==1)
	cnt++;
}
cout<<cnt<<endl;
//	cout<<"Prodip";


	return 0;
}