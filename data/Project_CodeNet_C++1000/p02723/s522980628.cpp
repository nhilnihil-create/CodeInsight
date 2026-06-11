#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
int main(){
    string s; cin >> s;
    bool ok = true;
    for(int i=0; i<6; ++i){
        if(s[2]!=s[3]){ok = false; break;}
        if(s[4]!=s[5]){ok = false; break;}
    }
    if(ok){cout << "Yes" << endl;}
    else{cout << "No" << endl;}
    return 0;
}