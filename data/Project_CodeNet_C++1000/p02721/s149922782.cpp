#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n); i > 0; i--)
#define print(n) cout << n << endl

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n,k,c;
    string s;
    cin >> n >> k >> c >> s;
    vector<ll> f(k);
    vector<ll> r(k);
    int x = 0;
    rep(i,n){
        if(s[i]=='o'){
            f[x] = i;
            i += c;
            x++;
            if(x>=k) break;
        }
    }
    x = k-1;
    rrep(i,n){
        if(s[i-1]=='o'){
            r[x] = i-1;
            i -= c;
            x--;
            if(x<0) break;
        }
    }
    rep(i,k) if(f[i]==r[i]) print(f[i]+1);

    return 0;
}