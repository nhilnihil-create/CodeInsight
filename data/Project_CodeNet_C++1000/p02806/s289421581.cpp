#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    // Your code here!
    ll n,sum=0;
    cin>>n;
    vector<pair<string,ll>>a(n);
    rep(0,i,n){
        cin>>a[i].first>>a[i].second;
        sum+=a[i].second;
    }
    ll tmp=0;
    string x;
    cin>>x;
    rep(0,i,n){
        tmp+=a[i].second;
        if(a[i].first==x){
            cout<<sum-tmp;
            return 0;
        }
    }
}