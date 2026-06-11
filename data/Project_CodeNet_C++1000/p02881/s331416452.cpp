#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}


int main() {
    ll n;
    cin >> n;
    ll ans = 1e18;
    ll tmp = 0;
    for(ll i = 1;i<=1000000;i++) {
        if(n%i==0) {
            ll j = n/i;
            tmp += (i-1)+(j-1);
            ans = min(ans,tmp);
        }
        tmp = 0;
    }
    cout << ans << endl;
}