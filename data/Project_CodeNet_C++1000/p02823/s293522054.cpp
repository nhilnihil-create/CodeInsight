#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long n, a, b;
	cin>>n>>a>>b;
	if((b-a)%2==0) cout<<(b-a)/2;
	else{
		long long ans=a+(b-a-1)/2;
		ans=min(ans, n-b+1+(b-a-1)/2);
		cout<<ans;
	}
}