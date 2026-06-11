#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
int32_t main(){
    IOS;
    string t;
    cin >> t;
    if(t[2] == t[3] && t[4] == t[5]){
    	cout << "Yes\n";
    } else {
    	cout << "No\n";
    }
    return 0;
}

