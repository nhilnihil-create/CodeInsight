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
    map<string, ll> m;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        sort(ALL(s));
        m[s]++;
    }

    ll ans = 0;
    for(auto p : m){
        if(1 < p.second){
            ans += (p.second * (p.second - 1) / 2);
        }
    }
    cout << ans << endl;

    return 0;
}
