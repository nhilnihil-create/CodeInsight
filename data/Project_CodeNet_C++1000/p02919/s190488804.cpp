#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define endl '\n'
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

const ll INF=1e15;


int main(){
    ll n;
    cin >> n;
    vector<ll> p(n),pos(n);
    set<ll> s;
    rep(i,n){
        cin >> p[i];
        p[i]--;
        pos[p[i]]=i;
    }
    ll ans=0;
    rep(i,n){
        ll now=pos[n-1-i];
        s.insert(now);
        //左に最大値を含む場合
        if(*s.begin()<now){
            ll le=0,ri=n-1;
            auto it=s.lower_bound(now);
            it--;
            ll mx=*it;
            if(*s.begin()<mx){
                it--;
                le=*it;
                le++;
            }
            if(*s.rbegin()>now){
                it=s.lower_bound(now);
                it++;
                ri=*it;
                ri--;
            }
            ans+=(ri-now+1)*(mx-le+1)*(n-i);
        }
        //右に最大値を含む場合
        if(*s.rbegin()>now){
            ll le=0,ri=n-1;
            auto it=s.lower_bound(now);
            it++;
            ll mx=*it;
            if(*s.rbegin()>mx){
                it++;
                ri=*it;
                ri--;
            }
            if(*s.begin()<now){
                it=s.lower_bound(now);
                it--;
                le=*it;
                le++;
            }
            ans+=(ri-mx+1)*(now-le+1)*(n-i);
        }
    }
    cout << ans << endl;
    return 0;
}