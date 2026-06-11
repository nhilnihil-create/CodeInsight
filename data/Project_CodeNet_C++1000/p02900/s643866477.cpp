#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int a,b;cin>>a>>b;
    int g=__gcd(a,b);int cnt=0;
    for(int i=2;i*i<=g;i++){
        if(g%i==0){
            while(g%i==0){
                g/=i;
            }
            cnt++;
        }
    }
    if(g>1) cnt++;
    cout<<cnt+1;
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
