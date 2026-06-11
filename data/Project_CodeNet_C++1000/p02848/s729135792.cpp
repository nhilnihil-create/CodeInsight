#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n;
    string s;
    cin >> n >> s;
    string ans = "";
    rep(i,s.size()) {
        if((s[i]-'A')+n >= 26) {
            ans += 'A'+((s[i]-'A')+n)%26;
            continue;
        }
        ans += s[i]+n;
    }
    cout << ans << endl;
}