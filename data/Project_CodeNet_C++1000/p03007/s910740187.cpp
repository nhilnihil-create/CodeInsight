#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];

    vector<ll> plus,minus;
    rep(i,n){
        if(a[i]>=0) plus.push_back(a[i]);
        else minus.push_back(a[i]);
    }
    sort(all(plus));
    reverse(all(plus));
    sort(all(minus));
    if(minus.empty()) minus.push_back(plus.back()), plus.pop_back();
    if(plus.empty()) plus.push_back(minus.back()), minus.pop_back();

    vector<pair<ll,ll>> res;
    ll cur=minus[0];
    for(int i=0;i+1<plus.size();i++){
        res.push_back({cur,plus[i]});
        cur-=plus[i];
    }
    res.push_back({plus.back(),cur});
    cur=plus.back()-cur;
    for(int i=1;i<minus.size();i++){
        res.push_back({cur,minus[i]});
        cur-=minus[i];
    }

    cout<<cur<<endl;
    rep(i,res.size()) cout<<res[i].first<<" "<<res[i].second<<endl;
}

