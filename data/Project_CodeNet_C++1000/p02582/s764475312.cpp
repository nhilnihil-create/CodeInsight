#include <bits/stdc++.h>
using namespace std;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    string s;
    cin>>s;
    if(s[0]=='R'&&s[1]=='R'&&s[2]=='R'){
        cout<<3;
        return 0;
    }
    if((s[0]=='R'&&s[1]=='R')||s[1]=='R'&&s[2]=='R'){
        cout<<2;
        return 0;
    }
    if(s[0]=='R'||s[1]=='R'||s[2]=='R'){
        cout<<1;
        return 0;
    }
    cout<<0;
    return 0;
}
