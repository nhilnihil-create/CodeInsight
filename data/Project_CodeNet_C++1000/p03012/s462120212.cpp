#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int mod = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<int> w(n);
    rep(i,n) cin >> w.at(i);
    int ans = INF;
    rep(i,n){
        int s1=0,s2=0;
        rep(j,n){
            if(j <= i) s1 += w.at(j);
            else s2 += w.at(j);
        }
        ans =min(ans,abs(s1-s2));
    }
    cout << ans << endl;
}