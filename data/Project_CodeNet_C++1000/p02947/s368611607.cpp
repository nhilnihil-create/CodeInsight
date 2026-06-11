#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef unsigned long long ll;

int main(){
    ll n, m;
    cin >> n;

    ll ans = 0;

    unordered_map<string, ll>ct;
    string s;
    REP(i, n){
        cin >> s;
        sort(ALL(s));
        // cout << s << endl;

        if (ct[s] > 0){
            
            ans += ct[s];
            ct[s]++;
        }
        else ct[s] = 1;;
    }
    cout << ans << endl;

}