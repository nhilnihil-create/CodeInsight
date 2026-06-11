
/*
	*	Created By: 'Present_Sir'
	*	Created On: Friday 14 August 2020 01:00:51 PM IST
*/

#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long
using namespace std;


void solve(){
    int k;
    cin>>k;

    int ans = 0;

    for(int i=1; i<=k; ++i){
        for(int j=1; j<=k; ++j){
            for(int t=1; t<=k; ++t){
                ans += (__gcd(i,__gcd(j,t)));
            }
        }
    }
    cout<<ans<<endl;
}

int32_t main(){
    IOS;
    //int t; cin>>t; while(t--)
    {
        solve();
    }
    return 0;
}

