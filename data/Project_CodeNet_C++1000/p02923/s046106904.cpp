#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    h.push_back(1000000001);
    int ans = 0;
    int cnt = 0;
    rep(i,n){
        if(h[i]>=h[i+1]) cnt++;
        else{
            ans = max(ans,cnt);
            cnt = 0;
        }
    }
    cout << ans << endl;
}