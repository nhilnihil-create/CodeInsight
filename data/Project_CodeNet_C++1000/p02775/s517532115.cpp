#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long Int;


int main() {
    string S;
    cin >> S;

    Int N = S.size(); 
    
    vector<Int> dp1(N), dp2(N);

    if (S[0] - '0' <= 5) {
        dp1[0] = S[0] - '0';
    }
    else {
        dp1[0] = 11 - (S[0] - '0');
    }

    if (S[0] - '0' < 5) {
        dp2[0] = (S[0] - '0') + 1;
    }
    else {
        dp2[0] = 10 - (S[0] - '0');
    }

    rep1(i,N-1) {
        int now = S[i] - '0';
        dp1[i] = min(dp1[i-1]+now, dp2[i-1]+(10-now));
        dp2[i] = min(dp1[i-1]+now+1, dp2[i-1]+(9-now));
    }

    cout << dp1[N-1] << endl;
}