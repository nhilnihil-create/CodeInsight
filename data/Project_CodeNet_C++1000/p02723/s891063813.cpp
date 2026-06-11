#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define xrep(i, a, b) for (int i = int(a); i < int(b); ++i)
int main() {
    string S;
    cin >> S;
    if(S[3-1]==S[4-1]&&S[5-1]==S[6-1]) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}