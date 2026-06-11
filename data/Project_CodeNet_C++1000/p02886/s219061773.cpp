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
    vector<ll>d(n);
    for (int i = 0; i < n; ++i) {
        cin >>d[i];
    }
    ll ans=0;
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j <n; ++j) {
            ans+=d[i]*d[j];
        }
    }
    cout <<ans <<endl;
    return 0;
}