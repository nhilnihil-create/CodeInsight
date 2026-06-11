#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int INF = 2e9;

int main(){
    ll n;
    cin >> n;
    vector<string>  s(n);
    rep(i,n){
        cin >> s[i];
        sort(s[i].begin(),s[i].end());
    }
    sort(s.begin(),s.end());
    ll ans = 0;
    ll cnt = 1;
    rep(i,n-1){
        if(s[i] == s[i+1]) cnt++;
        else {
            ans += cnt*(cnt-1)/2;
            cnt = 1;
        }
    }
    ans += cnt*(cnt-1)/2;
    cout << ans << endl;
}