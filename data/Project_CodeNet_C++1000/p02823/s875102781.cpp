#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};

vector<pair<ll,ll>> f(ll n){
    vector<pair<ll,ll>> p;
    for(ll i = 2;i * i<=n;++i){
        if(n%i == 0){
            ll tmp = 0;
            while(n%i == 0){
                n/=i;
                tmp++;
            }
            p.push_back(make_pair(i,tmp));
        }
    }
    if(n != 1) p.push_back(make_pair(n,1));
    return p;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,a,b;
    cin >> n >> a >> b;
    ll ans = 0;
    if(a%2 == b%2){
        ans = abs(a-b);
        ans /= 2;
    }else {
        ll t;
        t = min(n-a,b-1);
        if(t == n-a) {
            ans += n-b;
            ans++;
            ll tmp = n - (a+ans);
            tmp /= 2; 
            ans += tmp;
        }else {
            ans += a-1;
            ans++;
            ll tmp = (b-ans) - 1;
            tmp /= 2;
            ans += tmp;
        }
    }
    cout << ans << endl;
    cout << endl;
    return 0;
}
