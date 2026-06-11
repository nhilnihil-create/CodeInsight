#include<bits/stdc++.h>
#define rint register int 
#define ll long long 
using namespace std;
ll A,B,V,W,T;
int main(){
	cin>>A>>V>>B>>W>>T;
	ll d=abs(A-B);
	if(A==B) cout<<"YES\n";
	else {
		if(d<=(V-W)*T) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}