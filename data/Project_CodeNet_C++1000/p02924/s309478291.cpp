#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n; cin>>n;
	ll ans=0;
	for(int i=1; i<n; i++){
		ans+=i;
	}
	cout<<ans<<endl;
}