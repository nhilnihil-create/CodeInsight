#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,d;
	cin>>n>>d;
	int ans=n/(2*d +1);
	if(n%(2*d +1)==0)cout<<ans;
	else cout<<ans+1;
}