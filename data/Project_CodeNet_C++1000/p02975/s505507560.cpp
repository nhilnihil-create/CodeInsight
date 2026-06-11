#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;

#define rep(i,n) for(ll i=0;i<ll(n);i++)
#define YESNO(T) if(T){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(T) if(T){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(T) if(T){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
const double pi = 3.14159265358979;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    map<ll,ll> mp;
    for (ll i = 0; i < n; i++){
        mp[a[i]]++;
    }

    bool ans = false;

    if (mp.size() == 1){
        if (a[0] == 0){
            ans = true;
        }
    }
    else if (mp.size() == 2){
        if (mp[0] == n/3 && mp[a[n-1]] == 2*n/3 && n%3 == 0){
            ans = true;
        }
    }
    else if (mp.size() == 3){
        ll x = 0;
        for (auto p : mp){
            auto k = p.first;
            x = x^k;
        }
        
        if (x == 0 && n%3 == 0){
            bool b = true;
            for (auto p : mp){
                auto v = p.second;
                if (v != n/3){
                    b = false;
                    break;
                }
            }
            if (b){
                ans = true;
            }
        }
    }

    YesNo(ans);


}