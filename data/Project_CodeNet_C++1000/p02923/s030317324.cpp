
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    ll n;
    cin >> n;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];

    ll count=0;
    ll ans=0;
    for(int i=0; i<n-1; i++){
        if(h[i] >= h[i+1]){
            count ++;
            ans = max(ans,count);
        }
        else{
            count = 0;
        }
    }
    cout << ans << endl;
}