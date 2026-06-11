
/*
	*	Created By: 'Present_Sir'
	*	Created On: Saturday 15 August 2020 01:47:47 PM IST
*/

#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long
using namespace std;

int fact(int x){
    if(x == 0){
        return 1;
    }
    if(x == 1){
        return 1;
    }
    return x*fact(x-1);
}
    

int nC3(int x){
    return ((x*(x-1)*(x-2))/6);
}

void solve(){
    int n;
    cin>>n;
    string t;
    cin>>t;
    set < string >  s;
    for(int i=0; i<10; ++i){
        for(int j=0; j<10; ++j){
            for(int k=0; k<10; ++k){
                string  p = "";
                p += (i+'0');
                p += (j+'0');
                p += (k+'0');
                s.insert(p);
            }
        }
    }


    int ans = 0;
    for(auto x: s){
        int j = 0;
        bool found = false;
        for(int i=0; i<n; ++i){
            if(x[j] == t[i]){
                ++j;
            }
            if( j == 3 ){
                found = true;
                break;
            }
        }
        if(found) ++ans;
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

