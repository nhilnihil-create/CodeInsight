/**
*    author:  souzai32
*    created: 14.08.2020 13:05:23
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s.at(i);
    sort(s.begin(),s.end());
    
    int ans=1;
    rep(i,n-1) if(s.at(i)!=s.at(i+1)) ans++;
    cout << ans << endl;

    return 0;
}