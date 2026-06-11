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
    ll n;cin >>n;
    vector<ll>a(n);
    vector<ll>b(n);
    vector<ll>c(n);
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
        a[i]--;
    }
    for (int i = 0; i < n; ++i) {
        cin >>b[i];
    }
    for (int i = 0; i < n-1; ++i) {
        cin >>c[i];
    }
    ll ans=0;
    for (int i =0; i < n; ++i) {
           ans+=b[a[i]];
    }
//    cout <<ans <<endl;
    for (int i = 0; i < n - 1; ++i) {
        if(a[i+1]==a[i]+1){
            ans+=c[a[i]];
        }
    }
    cout <<ans <<endl;
    return 0;
}