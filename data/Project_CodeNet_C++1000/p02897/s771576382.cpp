#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n;cin>>n;
    int x;
    if(n%2) x=n/2+1;
    else x=n/2;
    double ans=(1.0*x)/n;
    printf("%0.9f",ans);
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);	 
	int T=1;
	// cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
