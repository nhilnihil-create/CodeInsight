#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

vector<ll>a;
vector<ll>f;
ll n,k;
bool ch(ll x){
    ll cnt=0;
    for (int i = 0; i < n; ++i) {
        ll d=a[i]*f[i]-x;
        if(d<=0)continue;
        else {
            cnt+=(d-1)/f[i]+1;
        }
    }
    if(cnt>k)return false;
     return true;
}

int main(){
    cin >>n>>k;
    a.resize(n);
    f.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >>f[i];
    }
    sort(all(a));
    sort(all(f));
    reverse(all(f));
    ll ng=-INFll/2;
    ll ok=INFll/2;
    while(abs(ok-ng)>1){
        ll md=(ok+ng)/2;
        if(ch(md))ok=md;
        else ng=md;
//        cout <<ok <<" "<<ng<<endl;
    }
    ok=max(0LL,ok);
    cout<<ok<<endl;
    return 0;
}

