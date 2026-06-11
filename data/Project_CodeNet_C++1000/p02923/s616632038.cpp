#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> h(n-1);
    int b, ans = 0, cnt = 0;
    cin >> b;
    rep(i,n-1){
        cin >> h[i];
        if(b >= h[i]){
            ++cnt;
            b = h[i];
        }
        else{
            cnt = 0;
            b = h[i];
        }
        chmax(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}