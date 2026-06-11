#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)



vector<ll> zalgo(const string &s){
    ll n = (ll)s.size();
    vector<ll> a(n,0);
    a[0] = n;
    ll i = 1, j = 0;
    while (i < n){
        while (i+j < n && s[j] == s[i+j]){
            j++;
        }
        a[i] = j;
        if (j == 0){
            i++;
            continue;
        }
        ll k = 1;
        while (i+k < n && k+a[k] < j){
            a[i+k] = a[k];
            k++;
        }
        i += k;
        j -= k;
    }
    return a;
}




int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    rep1(i,n){
        string t = s.substr(i);
        auto lcp = zalgo(t);
        
        rep1(j,t.size()){
            ll l = min(lcp[j],j);
            ans = max(ans, l);
        }
    }
    cout << ans << endl;
}