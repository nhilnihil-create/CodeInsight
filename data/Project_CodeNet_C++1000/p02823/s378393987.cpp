#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <string.h>

using namespace std;
#define ll long long int

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n,a,b;
	cin>>n>>a>>b;
	ll ai=n-a;
	ll bi=b-1;
	if(abs(a-b)%2==0){
		ai=min(ai,bi);
		ai=min(abs(a-b)/2,ai);
		cout<<ai<<endl;
	}
	else{
		ll ax=a+abs(b-a)/2;
		ll bx=n-b+1+abs(a-b)/2;
		cout<<min(min(ai,bi),min(ax,bx))<<endl;
	}

	return 0;
}
