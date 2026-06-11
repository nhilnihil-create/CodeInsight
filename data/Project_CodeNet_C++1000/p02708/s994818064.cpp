#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef  long long ll;
typedef unsigned long long ull;
const ll LIM =1e9+7;

template<typename T>
void fin (T a){
    cout<<a<<endl;
    exit(0);
}
template<typename S>
void print(S a){
    cout<<a<<endl;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n,k;cin>>n>>k;
    n++;

    ll ans=0;
    for(int i=k;i<=n;i++){
//        ull mn = (i-1)*i/2;
//        ull mx = (n-1+n-i)*i/2;
        ull tmp = i*(n-i);
        if(tmp/i!=n-i){
            tmp =(i%LIM)*((n-i)%LIM);
        }
        ans+=tmp+1;
        if(ans>=LIM)ans%=LIM;
    }


/*
//    vector<vector<ll>> dp(n, vector<ll>(n));
    vector<ll> dp(n);

    dp.at(0) = 1;
    for(ll i=1;i<n;i++){
        for(ll j=1;j<=i;j++){
//            ll tmp = (dp.at(j-1)+(j-1)*(j-2)/2+i)-(dp.at(j)+j*(j-1)/2)+dp.at(j);
            ll tmp = dp.at(j)+dp.at(j-1);
            if(tmp>=LIM){tmp %=LIM;}
            dp.at(j) = tmp;

        }
    }
    ll ans = 0;
    for (ll i = k ; i < n; i++) {
        ans+=dp.at(i);
        if(ans>=LIM)ans%=LIM;
    }
*/
    fin(ans);
}
