#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    int n; cin >> n;

    map<string, int> mp;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        sort(ALL(s));
        mp[s]++;
    }

    ll ans = 0;
    for(auto p : mp){
        if(1 < p.second){
            ll i = p.second;
            ans += (ll)(i * (i - 1)) / 2;
        }
    }
    cout << ans << endl;

    return 0;
}
