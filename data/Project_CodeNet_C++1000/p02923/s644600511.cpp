#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h.at(i);
    int ans = 0;
    int now = 0;
    rep(i,n-1){ 
        if(h.at(i) >= h.at(i+1))now++;
        else now = 0;
        ans = max(ans,now);
    }
    cout << ans << endl;
}