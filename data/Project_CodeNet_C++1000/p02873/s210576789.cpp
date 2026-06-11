#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    ll ans=0;
    ll a=0,b=0;

    for(int i = 0; i < s.size()-1; i++) {
        if(s[i]=='<') a++;
        if(s[i]=='>') b++;
        if(s[i]=='>' && s[i+1]=='<'){
            ll x=max(a,b),y=min(a,b);
            x *= max(a,b)+1;
            y *= min(a,b)-1;
            x /= 2;
            y /= 2;
            ans += x+y;
            
            a=0,b=0;
        }
    }
    if(s[s.size()-1]=='<') a++;
    if(s[s.size()-1]=='>') b++;

    ll x=max(a,b),y=min(a,b);
    x *= max(a,b)+1;
    y *= min(a,b)-1;
    x /= 2;
    y /= 2;
    ans += x+y;

    cout << ans << endl;

    return 0;
}