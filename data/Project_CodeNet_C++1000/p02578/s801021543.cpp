#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
const int mod =1'000'000'007;

int main(){
    int n;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a.at(i);

    ll ans = 0;
    rep(i,n-1){
        if (a.at(i) > a.at(i+1)){
            ans += a.at(i) - a.at(i+1);
            a.at(i+1) += a.at(i) - a.at(i+1);
        }
    }

    cout << ans << endl;
    return 0;
}
