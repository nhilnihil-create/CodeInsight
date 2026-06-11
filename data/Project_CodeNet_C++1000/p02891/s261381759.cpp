#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)


int main(){
    string s; cin >> s;
    ll k; cin >> k;
    ll n = s.size();

    s += s;
    ll a=0,b=0;
    bool all_same = true;
    rep(i,n-1){
        if(s[i]!=s[i+1]){
            all_same = false;
            break;
        }
    }
    rep(i,n-1){
        if(s[i]==s[i+1]){
            a++;
            s[i+1] = '0';
        }
    }

    for(int i=n-1;i<2*n-1;i++){
        if(s[i]==s[i+1]){
            b++;
            s[i+1] = '0';
        }
    }
    if(!all_same) cout << a+b*(k-1) << endl;
    else cout << n*k/2 << endl;
}