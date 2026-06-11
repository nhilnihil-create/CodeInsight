#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll count=0;
    for(ll i=0;i<n-1;i++){
        if(s[i]!=s[i+1]) count++;
    }
    ll res=min(n-1,n-1-count+2*k);
    cout << res << endl;
    return 0;
}