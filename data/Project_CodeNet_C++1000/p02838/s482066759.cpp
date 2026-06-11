#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n;
    cin >> n;
    vector <ll> num(62,0);
    vector <ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n){
        rep(j,62){
            if((a[i]>>j)&1==1){
                ++num[j];
            }
        }
    }

    
    unsigned long long ans;
    ans=0;
    ll ni,sa,sb;
    ni=1;
    rep(j,62){
        sa=(num[j]*(n-num[j]))%1000000007;
        
        ans+=ni*sa;
        ans=ans%(1000000007);
        ni=(ni*2)%1000000007;
    }
    cout << ans << endl;
    

    return 0;
}