#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(void){
    string s;ll k;
    cin>>s>>k;
    ll n = s.size();
    vi a;
    a.push_back(1);
    
    for(int i=1; i<n; i++){
        if(s[i]==s[i-1])a.back()++;
        else a.push_back(1);
    }
    
    if(a.size()==1){
        cout << n*k/2 << endl;
    }else{
        ll ans = 0;
        if(s[0]!=s[n-1]){
            rep(i,a.size())ans += a[i]/2 * k;
            cout << ans << endl;
        }else{
            ans = a[0]/2 + a.back()/2;
            ans += (a[0]+a.back())/2 * (k-1);
            for(int i=1; i<a.size()-1; i++){
                ans += a[i]/2 * k;
            }
            cout << ans << endl;
        }
    }
    
    return 0;
}