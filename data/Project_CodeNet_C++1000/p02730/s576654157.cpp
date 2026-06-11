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
    ll n = s.length();
    rep1(i, n/2){
        if (s[i] != s[n/2+1+i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}