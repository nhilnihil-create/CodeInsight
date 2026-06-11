#include <iostream>
#include <bits/stdc++.h>

#define rep(i,z) for(int i = 0; i<(int)(z); i++)
#define rep1(i,z) for(int i = 1; i<=(int)(z); i++)
 
using namespace std;

typedef long long ll;
const ll MOD=1e9+7;
using pear = pair<int,int>;

int gcd(int x, int y){
    if(x % y == 0) return y;
    return gcd(y, x % y);
}

int main(){
    int k; cin>>k;
    ll ans = 0;
    rep1(i,k){
        rep1(j,k){
            int now = gcd(i,j);
            rep1(n,k){
                ans += gcd(now,n);
            }
        }
    }
    cout<<ans<<endl;
}
