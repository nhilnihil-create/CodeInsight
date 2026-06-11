#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s,t,r;
    cin>>s;
    ll n = s.size(), ans=0;
    for(int i=0; i<n; i++) {
        r += s[i];
        if(t != r) {
            t = r;
            r = "";
            ans++;
        }
    }
    cout<<ans;
}