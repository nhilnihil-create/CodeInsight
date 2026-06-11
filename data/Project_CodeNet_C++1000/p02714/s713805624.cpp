#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)

int main(){
    int n; cin >> n;
    string s; cin >> s;
    ll r=0,g=0,b=0;
    rep(i,n){
        if(s[i]=='R') r++;
        else if(s[i]=='G') g++;
        else b++;
    }
    ll res = r*g*b;

    rep(i,n-2){
        for(int j=i+1;j<n-1;j++){
            if(j-i <= n-1-j){
                int k = 2*j-i;
                if(s[i]!=s[j] && s[j]!=s[k] && s[k]!=s[i]) res--;
            }
        }
    }
    cout << res << endl;
}