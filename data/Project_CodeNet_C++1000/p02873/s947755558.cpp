#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

ll f(ll n1, ll n2){
    ll max_n = max(n1, n2);
    ll min_n = min(n1, n2);
    return max_n*(max_n+1)/2 + min_n*(min_n-1)/2;
}

int main()
{
    string s;
    cin >> s;

    vector<ll> a(s.size()+1, 0);

    ll ans = 0;
    ll end_i = -1;
    ll cnt1 = 0;
    ll cnt2 = 0;
    rep(i, s.size()){
        if (s[i] == '<'){
            if (end_i != -1) {
                ans += f(cnt1, cnt2);
                end_i = -1;
                cnt1 = 0;
                cnt2 = 0;
            }
            cnt1++;
        }else{
            cnt2++;
            end_i = i;
        }
    }

    ans += f(cnt1, cnt2);
    cout << ans << endl;

    return 0;
}
