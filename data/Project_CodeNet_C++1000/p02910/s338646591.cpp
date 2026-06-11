#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    string S;
    bool ok=true;

    cin >> S;

    rep(i,S.size()) {
        if(i%2==0) {
            if(S[i]=='L') {
                ok = false;
            }
        } else {
           if(S[i]=='R') {
                ok = false;
            } 
        }
    }

    if(ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
    
}