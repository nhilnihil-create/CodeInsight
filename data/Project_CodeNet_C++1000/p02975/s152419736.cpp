#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    map<ll,ll>mp;
    for(ll i=0;i<n;i++){
        mp[a[i]]++;
    }
    bool ok=false;

    if(mp.size()==1){
        if(a[0]==0) ok=true;
    }
    else if(mp.size()==2){
        if(mp[0]==n/3&&mp[a[n-1]]==2*n/3&&n%3==0){
            ok=true;
        }
    }
    else if(mp.size()==3){
        ll x=0;
        for(auto p:mp){
            auto k=p.first;
            x^=k;
        }
        if(x==0&&n%3==0){
            bool b=true;
            for(auto p:mp){
                auto v=p.second;
                if(v!=n/3){
                    b=false;
                }
            }
            if(b) ok=true;
        }
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}
