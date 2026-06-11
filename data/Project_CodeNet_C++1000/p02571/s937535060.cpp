#include <bits/stdc++.h>

using namespace std;

#define Fast  ios::sync_with_stdio(false); cin.tie(0)
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define S second
#define F first
typedef long long ll;
const ll mod = 1e9 + 7;
const ll N = 1e6 + 5;
ll inf = 1e18;

int main(){

    Fast;

    string s , t;
    cin >> s >> t;

    ll ans = s.size();

    for(int i = 0 ; i <= s.size() - t.size() ; i ++){
        ll tmp = 0;
        for(int j = i; j < i + t.size(); j++){
            if(s[j] != t[j-i])tmp ++;
        }
        ans = min(ans , tmp);
    }
    cout << ans ;
    return 0;
}
