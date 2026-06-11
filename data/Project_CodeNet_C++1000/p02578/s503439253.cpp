#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,i;
	cin>>n;
	ll x,s1=0,s2=0,m=0;
	for(i=1; i<=n; i++){
		cin>>x;
		s1+=x;
		if(x<m)	s2+=m;
		else	s2+=x;
		m=max(m,x);
	}	
	cout<<s2-s1;
	return 0;
}
