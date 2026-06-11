#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

bool kai(string S)
{
    rep(i, (int)S.size()) {
        if (S[i] != S[S.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    string S;
    cin >> S;

    bool b = kai(S);
    if (!b) {
        cout << "No" << endl;
        return 0;
    }

    string S2 = S.substr(0, (S.size() - 1)/2);
    b = kai(S2);
    if (!b) {
        cout << "No" << endl;
        return 0;
    }

    int N = S.size();
    string S3 = S.substr((N + 3)/2 - 1, N);
    b = kai(S3);
    if (!b) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    return 0;
}
