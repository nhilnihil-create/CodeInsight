/*
    Author - Param Kothari
    Ah shit, here we go again
*/

#include <bits/stdc++.h>
 
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define mk make_pair

typedef long long ll;
typedef long double ld;

void solve(){
    string s;
    cin >> s;
    int n = (int)s.size();
    for(int i = 0; i < n; i++){
        if(s[i] == '?') s[i] = 'D';
    }
    cout << s << "\n";
    return;
}

int main(){
    IOS;
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}