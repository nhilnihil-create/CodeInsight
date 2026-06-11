#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long double
typedef pair<ll,ll>pairs;
int main() {
	// your code goes here
	std::ios::sync_with_stdio(false);
	ll t,n,i,j,k,l,c=0,f;
	cin>>n;
	i=1;
	vector<ll>a(n+1);//b(n+1),d(n+1);
	map<ll,ll>m;
	while(i<=n)
	{
	    cin>>a[i];
	    if(m.find(a[i]+i)==m.end())
	        m.insert({i+a[i],1});
	    else
	        m[i+a[i]]++;
	    i++;
	}
	for(i=1;i<=n;i++)
	{
	    k=i-a[i];
	    if(m.find(k)!=m.end())
	        c+=m[k];
	}
	cout<<c<<"\n";
	return 0;
}
