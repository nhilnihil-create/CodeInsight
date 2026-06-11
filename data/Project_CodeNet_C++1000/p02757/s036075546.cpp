#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define LLINF 9223372036854775807
#define MOD ll(1e9+7)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr<<#x<<": "<<x<<endl


int main(){
    ll n, p;
    cin >> n >> p;

    string s;
    cin >> s;

    if(p==2){
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ll tmpnum = s[i]-'0';
            if(tmpnum%2 == 0){
                ans += i+1;
            }
        }
        cout << ans << endl;
    }else if(p==5){
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ll tmpnum = s[i]-'0';
            if(tmpnum%5 == 0){
                ans += i+1;
            }
        }
        cout << ans << endl;
    }else{
        map<ll, ll> mp;
        mp[0] = 1;
        ll coef = 1;
        ll num = 0;
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ll tmpnum = s[n-1-i]-'0';
            num += coef*tmpnum;
            num %= p;
            coef *= 10;
            coef %= p;
            mp[num]++;
        }
        for(auto itr = mp.begin(); itr != mp.end(); ++itr){
            ans += itr->second*(itr->second-1LL)/2;
        }
        cout << ans << endl;
    }


    return 0;

}
