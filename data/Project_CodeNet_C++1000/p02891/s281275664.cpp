#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(){
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    s += s;
    int i = 0, cnt = 1;
    ll ans1 = 0;
    while(i<n-1){
        if(s[i]==s[i+1])cnt++;
        else{
            ans1 += cnt/2;
            cnt=1;
        }
        i++;
    }
    if(cnt==n){
        ll ans = (ll)n*k/2;
        cout << ans << endl;
        return 0;
    }
    ll ans2=ans1;
    ans1 += cnt/2;
    while(i<2*n-1){
        if(s[i]==s[i+1]) cnt++;
        else{
            ans2+=cnt/2;
            cnt=1;
        }
        i++;
    }
    ans2+=cnt/2;
    ll ans =ans1 + (ans2-ans1)*(k-1);
    cout << ans << endl;
    return 0;
}