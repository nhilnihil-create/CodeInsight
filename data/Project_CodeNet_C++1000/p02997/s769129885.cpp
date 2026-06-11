#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e9;

//入力
ll n,k;

int main(){
    cin >> n >> k;
    ll flag = (n-1)*(n-2)/2;
    if(k>flag){
        cout << -1 << endl;
        return 0;
    }
    cout << n-1+(flag-k) << endl;
    rep(i,n-1){
        cout << 1 <<  ' ' << i+2 << endl;
    }
    bool end = false;
    for(int i=2;i<n;i++){
        if(flag==k)end=true;
        if(end)break;
        for(int j=i+1;j<=n;j++){
            if(end)break;
            cout << i << ' ' << j << endl;
            flag--;
            if(flag==k)end=true;
        }
    }
    return 0;
}
