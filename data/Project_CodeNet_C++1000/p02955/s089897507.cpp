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
    int n,k;cin >>n>>k;
    vector<int>a(n);
    ll sum=0;
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
        sum+=a[i];
    }
    unordered_map<ll,int>mp;
    for (ll i = 1; i*i<=sum; ++i) {
        if(sum%i==0){
            mp[i]++;
            mp[sum/i]++;
        }
    }
    auto add=[&](ll x){
        vector<int>r;
        for (int i = 0; i < n; ++i) {
            if(a[i]%x){
                r.push_back(a[i]%x);
            }
        }
        if(r.empty())return true;
        int m=r.size();
        sort(all(r));
        vector<ll>fsum(m+1,0);
        vector<ll>rsum(m+1,0);
        for (int i = 0; i < m; ++i) {
            fsum[i+1]=fsum[i]+r[i];
            rsum[m-i-1]=rsum[m-i]+(x-r[m-i-1]);
        }
//        cout <<x<<endl;
//        for (int i = 0; i <=m; ++i) {
//            cout <<rsum[i]<<" ";
//        }
//        cout <<endl;
        for (int i = 0; i <=m; ++i) {
//            cout <<x<<" "<<fsum[i]<<" "<<rsum[i]<<endl;
            if(fsum[i]==rsum[i]&&fsum[i]<=k)return true;
        }
        return false;
    };
    ll ans=0;
    for(auto p:mp){
        if(add(p.first))ans=max(ans,p.first);
    }
    cout <<ans <<endl;
}