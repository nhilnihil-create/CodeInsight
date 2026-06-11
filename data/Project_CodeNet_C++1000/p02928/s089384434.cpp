#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n;
    ll k;
    cin>>n>>k;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];

    ll ans=0;
    rep(i,n){
        ll sf=0;
        rep(j,i){
            if(a[i]>a[j]) sf++; 
        }
        ll tmp=sf;
        if(k%2==0){
            tmp=(tmp*(k/2))%MOD;
            tmp=(tmp*(k-1))%MOD;
        }
        else{
            tmp=(tmp*((k-1)/2))%MOD;
            tmp=(tmp*k)%MOD;
        }
        ans=(ans+tmp)%MOD;
        ll sb=0;
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]) sb++;
        } 
        tmp=sb;
        if(k%2==0){
            tmp=(tmp*(k/2))%MOD;
            tmp=(tmp*(k+1))%MOD;
        }
        else{
            tmp=(tmp*((k+1)/2))%MOD;
            tmp=(tmp*k)%MOD;
        }
        ans=(ans+tmp)%MOD;
    }

    cout<<ans<<endl;
}