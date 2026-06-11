#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

vector<ll>ok;
vector<ll>ng;
vector<P>ans;

void f(){
    if(ng.empty()){
        return;
    }
    ll copy=min(ng.size(),ok.size());
    auto addok=[&](){
        ll c=ok.back();ll d=ng.back();
        ok.pop_back();ng.pop_back();
        ans.push_back({c,d});
        ok.push_back(c-d);
    };
    auto addng=[&](){
        ll c=ok.back();ll d=ng.back();
        ok.pop_back();ng.pop_back();
        ans.push_back({d,c});
        ng.push_back(d-c);
    };
    for (ll i = 0; i < copy; ++i) {
        if(ok.size()>ng.size())addng();
        else addok();
    }
    f();
}

int main(){
    ll n;cin >>n;
    vector<ll>a(n);
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
    }
    sort(all(a));
    if(a[n-1]<0){
        ok.push_back(a.back());
        a.pop_back();
    }
    reverse(all(a));
    if(a[n-1]>=0){
        ng.push_back(a[n-1]);
        a.pop_back();
    }
    for (auto e:a) {
        if(e>=0)ok.push_back(e);
        if(e<0)ng.push_back(e);
    }
    f();
    cout <<ok[0]<<endl;
    for(auto p:ans){
        cout <<p.first<<" "<<p.second<<endl;
    }
    return 0;
}