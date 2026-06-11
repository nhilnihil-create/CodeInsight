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
//        if(r.size()%2==1)return false;
        sort(all(r));
        sum=0;
        int cnt=0;
        for (int i = 0; i < r.size(); ++i) {
            sum+=r[i];
        }
        if(sum%x!=0){
            return false;
        }
        reverse(all(r));
        int w=0;
        for (int i = 0; i < r.size(); ++i) {
            w += r[i];
            w += (x - r[i]);
            cnt+= (x - r[i]);
            if (w ==sum)break;
        }
        if(cnt>k)return false;
        return true;
    };
    ll ans=0;
    for(auto p:mp){
        if(add(p.first))ans=max(ans,p.first);
    }
    cout <<ans <<endl;
}
