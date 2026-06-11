
/*
	*	Created By: 'Present_Sir'
	*	Created On: Friday 14 August 2020 12:52:24 PM IST
*/

#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long
using namespace std;


void solve(){
    int a;
    cin>>a;

    while( a>0){
        if( a%10 == 7 ){
            cout<<"Yes"<<endl;
            return;
        }
        a /= 10;
    }
    cout<<"No"<<endl;
}

int32_t main(){
    IOS;
    //int t; cin>>t; while(t--)
    {
        solve();
    }
    return 0;
}

