#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    string S;
    cin >> S;

    if (S[0] == S[1] && S[2] == S[3] && S[1] != S[2]) cout << "Yes" << endl;
    else if (S[0] == S[2] && S[1] == S[3] && S[1] != S[2]) cout << "Yes" << endl;
    else if (S[0] == S[3] && S[1] == S[2] && S[0] != S[1]) cout << "Yes" << endl;
    else cout << "No" << endl;

        return 0;
}