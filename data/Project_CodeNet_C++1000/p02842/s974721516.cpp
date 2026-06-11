
/*
	*	Created By: 'Present_Sir'
	*	Created On: Saturday 15 August 2020 01:23:32 PM IST
*/

#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long
using namespace std;


void solve(){
    int n;
    cin>>n;
    int k = (n*100)/108;
    //cout<<k<<endl;
    if(((int)(k*(1.08))) == n){
        cout<<k<<endl;
        return;
    }
    //cout<<(int)((k+1)*(1.08))<<endl;
    if((int)((k+1)*(1.08)) == n){
        cout<<k+1<<endl;
        return;
    }
    cout<<":("<<endl;
    
}

int32_t main(){
    IOS;
    //int t; cin>>t; while(t--)
    {
        solve();
    }
    return 0;
}

