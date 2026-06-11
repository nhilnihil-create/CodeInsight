#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,d,a;
    cin >> n >> d >> a;
    vector<pair<ll,ll>> xh(n);
    for(ll i = 0; i < n; i++) {
        cin >> xh[i].first >> xh[i].second;
    }
    sort(xh.begin(),xh.end());
    for(int i = 0; i < n; i++) {
        xh[i].second = (xh[i].second + a-1)/a;
    }

//    for(int i = 0; i < n; i++) {
//        cout << xh[i].first << " " << xh[i].second << "\n";
//    }
    queue<pair<ll,ll>> q;
    ll now=0;
    ll ans=0;
    for(ll i = 0; i < n; i++) {

        if(!q.empty()) {
            while(q.front().first<xh[i].first && !q.empty()) {
                now-=q.front().second;
                q.pop();
            }
        }

        if(xh[i].second>now){
            q.push(make_pair(xh[i].first+2*d,xh[i].second-now));
            ans+=xh[i].second-now;
            now=xh[i].second;
        }
    }
    cout << ans << "\n";

    return 0;
}