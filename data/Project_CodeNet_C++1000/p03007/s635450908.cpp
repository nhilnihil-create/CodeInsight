#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end(),greater<int>());
    vector<int> plus = {a[0]};
    vector<int> minus = {a[n-1]};
    for(int i=1;i<n-1;i++){
        if(a[i] > 0) plus.push_back(a[i]);
        else minus.push_back(a[i]);
    }
    int c = 0;
    int ans = 0;
    vector<P> xy(n-1);
    if(plus.size() == 1){
        xy[c++] = P(plus[0],minus[0]);
        ans = plus[0] - minus[0];
        for(int i=1;i<minus.size();i++){
            xy[c++] = P(ans,minus[i]);
            ans -= minus[i];
        }
    }else{
        xy[c++] = P(minus[0],plus[0]);
        ans = minus[0] - plus[0];
        for(int i=1;i<plus.size()-1;i++){
            xy[c++] = P(ans,plus[i]);
            ans -= plus[i];
        }
        xy[c++] = P(plus.back(),ans);
        ans = plus.back() - ans;
        for(int i=1;i<minus.size();i++){
            xy[c++] = P(ans,minus[i]);
            ans -= minus[i];
        }
    }
    cout << ans << endl;
    rep(i,n-1) cout << xy[i].first << " " << xy[i].second << endl;
    return 0;
}
