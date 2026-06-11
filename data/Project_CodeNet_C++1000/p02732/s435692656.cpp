#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n;
    cin>>n;

    map<ll,ll> m;
    vector<ll> a(n);
    rep(i,n){
        cin>>a[i];
        m[a[i]]++;
    }

    ll sum=0;
    for(auto e : m){
        sum+=e.second*(e.second-1)/2;
    }
    //cout<<sum<<endl;
    rep(i,n){
        ll x=m[a[i]];
        ll tmp=x*(x-1)/2-(x-1)*(x-2)/2;
        cout<<sum-tmp<<endl;
    }
}