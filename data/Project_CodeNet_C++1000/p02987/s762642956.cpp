#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    string s;
    cin >> s;
    map<char, ll> check;
    rep1(i, 4){
        check[s[i]]++;
    }
    bool judge = true;
    rep1(i, 4){
        if (check[s[i]] != 2) judge = false;
    }
     
    if (judge) cout << "Yes" << endl;
    else cout << "No" << endl;
}