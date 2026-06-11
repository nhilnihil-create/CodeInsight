
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }



int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    //累積和
    vector<ll> sum(n+1);
    
    rep(i,n){
        sum.at(i+1) = sum.at(i) + a.at(i);
    }
        

    ll ans=1e20;
    rep(i,n){ //i番目で区切った時に何回操作が必要になるか
        ans = min(ans,abs(2*sum[i+1]-sum[n]));
    }

    cout << ans << endl;
   

}