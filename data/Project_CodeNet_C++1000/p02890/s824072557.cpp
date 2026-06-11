#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))
 
using namespace std;
 
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
 
const ll INF=1e9+7;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> s(n+1);
    rep(i,n){
        ll x;
        cin >> x;
        a[x-1]++;
    }
    sort(a.begin(),a.end());
    rep(i,n){
        s[i+1]=s[i]+a[i];
    }
    for(ll k=1;k<=n;k++){
        ll le=0,ri=n/k+1;
        while(ri-le>1){
            ll mid=(le+ri)/2;
            auto it=lower_bound(a.begin(),a.end(),mid)-a.begin();
            if(s[it]+(n-it)*mid>=mid*k){
                le=mid;
            }
            else{
                ri=mid;
            }
        }
        cout << le << endl;
    }
    return 0;
}