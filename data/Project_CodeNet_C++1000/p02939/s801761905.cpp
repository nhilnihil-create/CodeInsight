#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    string s;
    cin >> s;
    ll n=s.size();
    ll ans=n;
    vector<string>str(n+1,".");
    for(ll i=0;i<n;i++){
        str[i]=s[i];
    }
    for(ll i=0;i<n-1;i++){
        if(str[i]==str[i+1]){
            str[i+1]=str[i]+str[i+1];
            ans--;
            str[i+2]="XXX";
        }
    }
    cout << ans << endl;
}