#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n;

int main(void){
    cin >> n;
    vector<vector<lli>> presuf(10, vector<lli>(10)), sufpre(10, vector<lli>(10));
    for(int i = 1; i <= n; i++){
        string s = to_string(i);
        presuf[s[0]-'0'][s[s.size()-1]-'0']++;
        sufpre[s[s.size()-1]-'0'][s[0]-'0']++;
    }
    lli ans = 0;
    rep(i, 10){
        rep(j, 10){
            ans += presuf[i][j]*sufpre[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}
