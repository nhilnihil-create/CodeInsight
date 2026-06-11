#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// your code goes here
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<<max({a*c,a*d,b*c,b*d})<<"\n";
	return 0;
}