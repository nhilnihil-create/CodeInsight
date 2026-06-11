#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll l, a[500001];
ll ans; 
int main()
{
	cin>>s;
	s=" "+s;
	l=s.length()-1;
	for(int i=1;i<=l;i++) (s[i] == '<') ? (a[i+1] = a[i] + 1) : (a[i+1]);
	for(int i=l;i>=1;i--) (s[i] == '>') ? (a[i] = max(a[i], a[i+1]+1)) : (a[i]);
	for(int i=1;i<=l+1;i++) 
	ans+=a[i];
	cout<<ans<<endl;
	return 0;
}