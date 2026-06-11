// C - Guess The Number
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> s(m), c(m);
    rep(i, m) cin >> s[i] >> c[i];
    rep(i, 1000){
        string str = to_string(i);
        if(str.size() != n) continue;
        bool ok = true;
        rep(j, m){
            if(str[s[j]-1] != c[j]+'0') ok = false;
        }
        if(ok){
            cout << str << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}