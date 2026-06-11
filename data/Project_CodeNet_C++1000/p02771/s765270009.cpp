#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define xrep(i,a,b) for(int i=int(a);i<int(b);++i)
using ll = long long;


int main() {
    int A, B, C;
    cin >> A >> B >> C;
    vector<int> As = {A, B, C};
    int cnt = 0;
    rep(i, 3) {
        rep(j, 3) {
            if(i==j) continue;
            if(As[i] == As[j]) {
                ++cnt;
            }
        }
    }   
    if(cnt==2) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}