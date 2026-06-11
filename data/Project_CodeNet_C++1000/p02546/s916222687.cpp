#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() { 
    string S;
    cin >> S;

    if (S[S.size() - 1] == 's') {
        cout << S + "es" << "\n";
    } else {
        cout << S + "s" << "\n";
    }
    return 0;
}
