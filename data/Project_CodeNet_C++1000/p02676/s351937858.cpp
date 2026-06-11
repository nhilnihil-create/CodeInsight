
/*
	*	Created By: 'Present_Sir'
	*	Created On: Friday 21 August 2020 11:09:23 AM IST
*/

#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long
using namespace std;


void solve(){
    int n;
    cin>>n;

    string s;
    cin>>s;

    if((int)s.length() > n){
        string st = s.substr(0,n);
        st += "...";
        cout<<st<<endl;
    }else{
        cout<<s<<endl;
    }
}

int32_t main(){
    IOS;
    //int t; cin>>t; while(t--)
    {
        solve();
    }
    return 0;
}

