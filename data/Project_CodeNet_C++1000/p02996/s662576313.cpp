#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;


int main() {
    ll n; cin >> n;
    vector<pair<ll,ll>> c(n,pair<ll,ll>(0,0));
    rep(i,n) cin >> c.at(i).second >> c.at(i).first;
    
    sort(c.begin(),c.end());
    ll sum=0;
    rep(i,n){
        sum += c[i].second;
        if(sum>c[i].first){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

}