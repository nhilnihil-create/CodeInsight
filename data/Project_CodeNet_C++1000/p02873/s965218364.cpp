#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(void){
    string s;
    cin>>s;
    int n = (int)s.size()+1;
    
    vi a(n, 0);
    
    for(int i=1; i<n; i++){
        if(s[i-1]=='<')
            a[i] = max(a[i], a[i-1]+1);
    }
    for(int i=n-2; i>=0; i--){
        if(s[i]=='>'){
            a[i] = max(a[i], a[i+1]+1);
        }
    }
    
    ll ans = 0;
    rep(i,n)ans += a[i];
    
    cout << ans << endl;
    return 0;
}