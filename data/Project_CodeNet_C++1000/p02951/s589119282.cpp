#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main() {
	// your code goes here
	ll a,b,c;
	cin>>a>>b>>c;
	ll rem=a-b;
	if(rem==c || c<rem){
		cout<<0<<endl;
	}
	else if(c>rem){
		cout<<c-rem<<endl;
	}
	return 0;
}