#include<bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
using namespace std;

signed main(){
	ios_base::sync_with_stdio(0);
	int x;
	cin>>x;
	if(x<600) cout<<8;
	else if(x>=600&&x<800) cout<<7;
	else if(x>=800&&x<1000) cout<<6;
	else if(x>=1000&&x<1200) cout<<5;
	else if(x>=1200&&x<1400) cout<<4;
	else if(x>=1400&&x<1600) cout<<3;
	else if(x>=1600&&x<1800) cout<<2;
	else cout<<1;
	re 0;
}
