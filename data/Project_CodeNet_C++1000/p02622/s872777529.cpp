#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    string s1,s2;
    cin>>s1>>s2;
    ll len=s1.size();
    ll ans=0;
    for(ll i=0;i<len;i++){
        if(s1[i]!=s2[i])    ans++;
    }
    cout<<ans;
    return 0;
}
