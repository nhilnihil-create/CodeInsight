
/*
	*	Created By: 'Present_Sir'
	*	Created On: Friday 21 August 2020 10:54:23 AM IST
*/

#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long
using namespace std;


void solve(){
    int n;
    cin>>n;
    int a1[] = { 2, 4, 5, 7, 9 };
    int a2[] = { 0, 1, 6, 8 };
    
    for(int i=0; i<5; ++i){
        if(n%10 == a1[i]){
            cout<<"hon"<<endl;
            return;
        }
    }

    for(int i=0; i<4; ++i){
        if(n%10 == a2[i]){
            cout<<"pon"<<endl;
            return;
        }
    }
    cout<<"bon"<<endl;
    return;
}

int32_t main(){
    IOS;
    //int t; cin>>t; while(t--)
    {
        solve();
    }
    return 0;
}

