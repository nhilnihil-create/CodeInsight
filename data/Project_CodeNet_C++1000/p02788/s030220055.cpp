#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
using ll = long long;

int main()
{
    ll i,j;
    ll n,d,a;
    cin >> n >> d >> a;
    vector<pair<ll,ll>> x(n);
    for(i = 0;i < n;++i){
        cin >> x.at(i).first >> x.at(i).second;
    }
    sort(all(x));
    ll ans = 0;
    queue<pair<ll,ll>> que;
    ll num = 0;
    for(i = 0;i < n;++i){
        while(!que.empty() && que.front().first < x.at(i).first){
            num -= que.front().second;
            que.pop();
        }
        x.at(i).second -= num;
        if(x.at(i).second <= 0) continue;
        ll tmp = ((x.at(i).second-1)/a+1)*a;
        ans += tmp/a;
        que.emplace(x.at(i).first + 2*d, tmp);
        num += tmp;
    }
    cout << ans << endl;
    return 0;
}