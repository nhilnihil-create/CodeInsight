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
    s += "!";
    int ans = 0;
    string t = "?";
    rep(i,n){
        ++ans;
        string u = "?";
        u += s[i];
        if(t != u){
            t = u;
        }
        else{
            t = s[i];
            t += s[i+1];
            if(s[i+1] == '!') --ans;
            ++i;
        }
        //cout << t << endl;
    }
    cout << ans << endl;
    return 0;
}
