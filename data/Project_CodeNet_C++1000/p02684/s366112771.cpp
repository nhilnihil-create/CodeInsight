#include <bits/stdc++.h>
using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pl= pair<ll,ll>;
using ld=long double;
using V=vector<int>;
using Vl=vector<ll>;
using VV=vector<vector<int>>;
using VVl=vector<vector<ll>>;

int main(){
    ll n,k;cin >>n>>k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
    }
    map<ll,int>memo;//memo[x]=xの初出位置
    ll x=1;
    for (ll i = 0; i <k; ++i) {
        if(memo[x]){
            auto t=i-memo[x],c=(k-1-i)/t;//t=周期　c=どれくらい周期を回せるか
            i+=c*t;
        }
        else {
            memo[x]=i;
        }
        x=a[x-1];
    }
    cout <<x<<endl;
}