#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll a,v,b,w,t,g;
	cin>>a>>v>>b>>w>>t;
	if(a>b) g = a-b;
	if(b>a) g = b-a;
	if(g <= t * (v-w)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}