
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }


int main(){
    int n; cin >> n;
    vector<int> accum(n+1); //累積和
    vector<int> w(n);

    accum[0] = 0;
    rep(i,n) cin >> w.at(i);

    for(int i=1; i<n+1; i++){
        accum.at(i) = accum.at(i-1) + w.at(i-1);
    }
    

    int ans = 1e9;
    rep(i,n){
        ans = min(ans,abs(accum.at(n) - 2*accum.at(i)));
    }
    cout << ans << endl;


}