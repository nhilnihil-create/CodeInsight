#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define xrep(i,a,b) for(int i=int(a);i<int(b);++i)
using ll = long long;


int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int cnt = 0;
    rep(i, N-2) {
        if(S[i]=='A') {
            if(S[i+1]=='B'&&S[i+2]=='C') cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}