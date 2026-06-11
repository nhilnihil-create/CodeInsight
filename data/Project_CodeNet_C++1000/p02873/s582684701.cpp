#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;

ll cal(ll k){
    ll sum = 0;
    for (ll i = 1; i <= k; ++i)
    {
        sum += i;
    }
    if(k <= 0) return 0;
    else return sum;
}

int main() {

    string s; cin >> s;
    ll ans = 0;
    ll cur = 0;
    ll streak = 0;
    rep(i,s.length()){
        if(s[i] == '<'){
            if(streak != 0){
                if(streak +1 > cur){
                    ans += cal(streak);
                    ans -= cur;
                }else{
                    ans += cal(streak-1);
                }
                cur = 0;
            }
            cur ++;
            ans += cur;
            streak = 0;
        }else {
            streak ++;
        }
    }

    if(streak != 0){
        if(streak +1 >= cur){
            ans += cal(streak);
            ans -= cur;
        }else{
            ans += cal(streak-1);
        }
    }

    cout << ans;
    return 0;
}









