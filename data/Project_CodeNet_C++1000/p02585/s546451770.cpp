#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}
const int mod = 1000000007;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int>p(n);
    vector<int>c(n);
    rep(i,n) {
        cin >> p[i];
        p[i]--;
    }
    rep(i,n) {
        cin >> c[i];
    }
    ll ans = -1001001001;
    rep(i,n) {
        vector<int>s;
        int x = p[i];
        ll tot = 0;
        while(true) {
            s.push_back(c[x]);
            tot += c[x];
            if(x==i) break;
            x = p[x];
        }
        ll sum = 0;
        int l = s.size();
        rep(j,l) {
            if(j+1 > k) break;
            sum += s[j];
            ll now = sum;
            if(tot > 0) {
                ll e = (k-j-1)/l;
                now += tot*e; // 周期をとれるだけとって加算
            }
            ans = max(ans,now);
        }
    }
    cout << ans << endl;
}