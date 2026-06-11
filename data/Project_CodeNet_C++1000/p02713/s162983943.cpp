#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
using ll = long long;
using namespace std;
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
int main(){
    int n;cin>>n;
    ll ans=0;
    rep1(i,n) rep1(j,n) rep1(k,n){
        ans+=gcd(gcd(i,j),k);
    }
    cout<<ans<<endl;
}