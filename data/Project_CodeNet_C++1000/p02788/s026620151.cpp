#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i < (n+1); ++i)
using namespace std;
using ll = long long;
const int INF = +100100100;
typedef pair<int,int> P;


int main(){
    int n,d,a;
    cin >> n >> d >> a;
    d= d*2;
    vector<P> T(n);
    queue<pair<ll,ll>> q;
    rep(i,n){
        cin >> T[i].first >> T[i].second;
    } 
    sort(T.begin(),T.end());
    ll ans=0;
    ll tot =0;
    rep(i,n){
        ll x = T[i].first;
        ll h = T[i].second;
        while(!q.empty()&& q.front().first<x){
            tot -= q.front().second;
            q.pop();
        }
        h-= tot;
        if(h>0){
            // 切り上げは(以下のように書く)
            ll num = (h+a-1)/a;
            ans += num;
            ll damage  = num * a;
            tot += damage;
            q.emplace(x+d, damage);
        }
    }
    cout << ans << endl;
    return 0;
}