#include <bits/stdc++.h>
template<class T> inline bool chmin(T&a, T b){if(a > b){a = b; return true;}else{return false;}}
template<class T> inline bool chmax(T&a, T b){if(a < b){a = b; return true;}else{return false;}}
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1.0)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    ll a = (n-1)*(n-2)/2;
    if(a < k)cout << -1 << endl;
    else{
        cout << n-1+a-k << endl;
        REP(i, n-1){
            cout << 1 << " " << i+1 << endl;
        }
        ll cnt = 3, now = 2;
        rep(i, a-k){
            if(cnt > n){now++; cnt = now+1;}
            cout << now << " " << cnt << endl;
            cnt++;
        }
    }
}