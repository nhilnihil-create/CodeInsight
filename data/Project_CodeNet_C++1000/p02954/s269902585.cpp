#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    string s;
    cin >> s;
    ll n = s.size();
    vector<ll> a(n);
    ll r = 1, l = 0;
    ll res, cnt;
    bool flag = true;
    for (ll i=1; i<(n); i++){
        if (s[i]=='R' && flag) r++;
        if (s[i]=='L'){
            if (flag) res = i;
            l++;
            flag = false;
        }
        if ((s[i]=='R' && !(flag)) || i==n-1){
            cnt = r + l;
            a[res-1] = cnt/2 + (r%2==1 && cnt%2==1);
            a[res] = cnt/2 + (l%2==1 && cnt%2==1);
            r = 1;
            l = 0;
            flag = true;
        }
    }
    rep1(i, n){
        if (i<n) cout << a[i] << " ";
        else cout << a[i] << endl;
    }
}