//
//  main.cpp
//  ABC136E
#include <iostream>
#include <vector>
#include <set>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;int main(int argc, const char * argv[]) {
    ll n,k;
    cin>>n>>k;
    vector<int>a(n);
    ll sum=0; // 操作後も合計は変わらないことを利用する
    rep(i,n){
        cin>>a.at(i);
        sum+=a.at(i);
    }
    set<ll> candidates; // 合計から、最大公約数の候補を列挙するset　重複なし
    for(int i=1;i*i<=sum;i++){
        if(sum%i==0){
            candidates.insert(i);
            candidates.insert(sum/i);
        }
    }
    ll ans=1;
    for(ll x : candidates){
        ll need;
        vector<ll>r(n);
        rep(i,n) r.at(i)=a.at(i)%x;
        sort(r.begin(),r.end());
        ll tot=0;
        rep(i,n) tot+=r.at(i);
        ll right=tot/x;
        ll left=n-right;
        need=0;
        rep(i,left){
            need+=r.at(i);
        }
        if(need<=k) ans=max(ans,x);
    }
    cout<<ans<<endl;
    return 0;
}
