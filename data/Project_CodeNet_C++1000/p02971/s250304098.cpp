#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
#define pb push_back
int main(void){
    ll n;
    cin>>n;
    vector<pair<ll,ll>>a(n);
    rep(0,i,n){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a.begin(),a.end());
    rep(0,i,n){
        if(i==a[n-1].second){
            cout<<a[n-2].first<<endl;
        }else{
            cout<<a[n-1].first<<endl;
        }
    }
}