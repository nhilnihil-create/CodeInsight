/**
*    author:  souzai32
*    created: 01.08.2020 19:02:17
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    string s;
    cin >> s;
    int n=s.size();
    int ans=n;
    rep(i,n-1){
        if(s.at(i)==s.at(i+1)){
            ans--;
            i+=2;
        }
    }
    cout << ans << endl;

    return 0;
}