#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

int k;

void solve(){

    cin >> k;
    string s;
    cin >> s;

    if(s.length() <= k){
        cout << s << endl;
    }
    else{

        s = s.substr(0,k);
        s += "...";
        cout << s << endl;
    }

}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}