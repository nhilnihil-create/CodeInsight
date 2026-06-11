#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int wa[200010];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    vector<ll> a(n);
    ll sum = 0;
    rep(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    ll ans = 1LL<<60;
    ll le=0, ri=sum;
    rep(i, n){
        le+=a[i]; ri = sum-le;
        ans = min(ans, abs(le-ri));
    }
    cout<<ans<<endl;
}