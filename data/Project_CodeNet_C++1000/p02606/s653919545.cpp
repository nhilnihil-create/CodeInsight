#include<bits/stdc++.h> 
using namespace std;

#define int long long

const int N = 1e5 + 5, MOD = 1e9 + 7;

int32_t main(){

	int l,r,d; cin>>l>>r>>d;

	int ans=0;

	for(int i=l;i<=r;i++){
		ans+=(i%d==0);
	}	    

	cout<<ans<<endl;
    
    return 0;
    
}
