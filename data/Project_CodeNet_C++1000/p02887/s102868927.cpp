#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n; 
    string s;
    cin >> n >> s;
    char c = '#';
    int ans = 0;
    rep(i,s.size()){
        if(c == s.at(i)) continue;
        c = s.at(i);
        ans++;
    }
    cout << ans << endl;
}