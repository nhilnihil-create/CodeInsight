#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define ll long long
const ll mod=1e9+7;

int main(){
    int n;cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<ll> d0(60,0),d1(60,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<60;j++){
            if(a[i]&1) d1[j]++;
            else d0[j]++;
            a[i]>>=1;
        }
    }
    ll ans=0;
  ll x=1;
    for(int i=0;i<60;i++){
        ans=(ans+(d0[i]*d1[i]%mod)*x%mod)%mod;
      x=x*2%mod;
    }
    cout<<ans<<endl;
    return 0;
}