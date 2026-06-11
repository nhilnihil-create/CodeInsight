#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    int n;cin >>n;
    vector<P>pos(n);
    for (int i = 0; i < n; ++i) {
        ll x,range;cin >>x>>range;
        pos[i]={x+range,x-range};//r,l
    }
    sort(all(pos));
    int ans=0;
    ll r=-INFll;
    for (int i = 0; i < n; ++i) {
        if(r<=pos[i].second){
            ans++;
            r=pos[i].first;
        }
    }
    cout <<ans <<endl;
}
