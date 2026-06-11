#include <bits/stdc++.h>
#define inf 100000000
#define rep(i,n) for(int i=0;i<n;i++) 
using namespace std;
typedef long long ll;



int main (){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string k = s;
    sort(k.begin(), k.end());
    ll ans = 0;
    rep(i,n){
        if(k[i]=='R'&&s[i]=='W'){
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}