#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    string s; cin >> s;
    int r = 0;
    for(int i=0; i<n; ++i){
        if(s[i]=='R'){r++;}
    }
    int res = 0;
    for(int i=0; i<r; ++i){
        if(s[i]=='W'){res++;}
    }
    cout << res << endl;
    return 0;
}