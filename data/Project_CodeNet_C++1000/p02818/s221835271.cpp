#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,c;
	cin>>a>>b>>c;
	if(c>=a+b) cout<<0<<" "<<0;
	else if(c>=a) cout<<0<<" "<<b-(c-a);
	else cout<<a-c<<" "<<b;
}