#include <bits/stdc++.h>
using namespace std;
#define re return
#define ll long long
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	long long n;
	cin>>n;
	ll ans=0;
	for(int i=1;i<n+1;i++){
		ll use;
		use=n/i;
		ans+=(use*(use+1)/2)*i;
	}
	cout<<ans<<endl;
	re 0;
}