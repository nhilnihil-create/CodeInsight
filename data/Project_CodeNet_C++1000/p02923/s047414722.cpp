#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
/////////////////////////////////
int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    vector<int> cnt(n,0);
    int ans = 0;
    for (int i = n - 2; i >= 0;i--){
        if(h[i]>=h[i+1])
            cnt[i] += cnt[i + 1] + 1;
    ans = max(ans, cnt[i]);}
    cout << ans << endl;
}