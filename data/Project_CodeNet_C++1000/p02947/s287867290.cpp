#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
/////////////////////////////////
int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) {
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
    }
    sort(s.begin(), s.end());
    ll ans = 0;
    ll cnt = 1;
    rep(i,n-1){
        if(s[i]==s[i+1])
            cnt++;
        else{
            ans += (cnt - 1) * cnt / 2;
            cnt = 1;
        }
    }
    ans += cnt * (cnt - 1) / 2;
    cout << ans << endl;
}