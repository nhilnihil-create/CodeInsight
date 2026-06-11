#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int K;
    cin >> K;

    ll ans=0;
    rep(i, K+1)rep(j, K+1)rep(k, K+1){
        if(i*j*k!=0){
            ans+=gcd(i, gcd(j, k));
        }
    }
    cout<<ans<<endl;
    return 0;
}