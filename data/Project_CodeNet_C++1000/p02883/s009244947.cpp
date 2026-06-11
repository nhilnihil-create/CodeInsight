#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;
ll n,k;
vector<ll>a;
vector<ll>f;
bool ch(ll x){
    ll cnt=0;
    for (int i = 0; i < n; ++i) {
        if(a[i]*f[i]-x<=0)continue;
        ll d=a[i]*f[i]-x;
        cnt+=(d-1)/f[i]+1;
    }
    if(cnt<=k)return true;
    return false;
}

int main(){
    cin >>n>>k;
    a.resize(n);
    f.resize(n);
    ll sum=0;
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
        sum+=a[i];
    }
    if(sum<=k){
        cout <<0<<endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >>f[i];
    }
    sort(all(a));
    sort(all(f));
    reverse(all(f));
    ll ok=INFll,ng=0;
    while(abs(ok-ng)>1){
        ll md=(ok+ng)/2;
        if(ch(md))ok=md;
        else ng=md;
    }
    cout <<ok<<endl;
    return 0;
}