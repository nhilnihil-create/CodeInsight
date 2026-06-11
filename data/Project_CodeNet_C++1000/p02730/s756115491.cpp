#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.size();
    bool ok = true;
    rep(i,n/2) if(s[i] != s[n-1-i]) ok = false;
    int m = (n-1)/2;
    rep(i,m/2) if(s[i] != s[m-1-i]) ok = false;
    int k = (n+3)/2 - 1;
    rep(i,m/2) if(s[i+k] != s[n-1-i]) ok = false;
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
