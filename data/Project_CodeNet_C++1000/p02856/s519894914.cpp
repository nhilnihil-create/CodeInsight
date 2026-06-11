#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    int M; cin >> M;
    ll ans = 0;
    vector<ll> digits;
    rep(i, M){
        ll d, c; cin >> d >> c;
        ll m;
        m = (d*c-1) / 9; 
        ans += c-1+m;
        digits.push_back(d*c-9*m);
    }

    
    rep(i, digits.size()-1){
        ll val = digits[i] + digits[i+1];
        if(val >= 10){
            digits[i] = 1;
            digits[i+1] = val % 10;
            i--;
        }
        else digits[i+1] = val;
        ans++;
    }
    cout << ans << endl;
    return 0;
}