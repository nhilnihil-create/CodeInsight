#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    int ans = s.size();
    rep(i,s.size()-1) {
        if(s[i]==s[i+1]) {
            --ans;
            i+=2;
        }
    } 
    cout << ans << endl;
    return 0;
}