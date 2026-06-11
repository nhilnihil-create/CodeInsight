// C - gacha
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    int ans = 1;
    sort(s.begin(), s.end());
    rep(i, n-1){
        if(s[i] != s[i+1]) ans++;
    }
    cout << ans << endl;
    return 0;
}