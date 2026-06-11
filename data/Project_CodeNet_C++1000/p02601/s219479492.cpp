#include<bits/stdc++.h>
#define endl '\n'
#define int long long
 
using namespace std;
 
int32_t main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	// r g b
	// b > g > r

	int r,g,b,k;
	cin>>r>>g>>b>>k;	

	while(g<=r && k){
		g<<=1;
		k--;
	}

	while(b<=g && k){
		b<<=1;
		k--;
	}

	if(r<g && g<b)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	return 0;
}
