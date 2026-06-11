#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> s(m);
    vector<char> c(m);
    rep(i,m) {
        cin >> s[i] >> c[i];
        s[i]--;
    }
    int ans = -1;
    int st = pow(10,n-1);
    if(n == 1) st = 0;
    for (int i = st;i < pow(10,n);i++){
        string num = to_string(i);
        bool f = true;
        rep(j,m){
            if(num[s[j]] != c[j]) f=false;
        }
        if(f) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}