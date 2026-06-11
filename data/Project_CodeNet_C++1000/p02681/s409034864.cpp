#include <bits/stdc++.h>          
using namespace std;
typedef long long ll;

int main() {
    string S, T, ans="Yes";
    cin >> S >> T;
    int Ns = S.size(), Nt = T.size();
    for (int i=0; i<Ns; i++) {
        if (S[i]!=T[i]) {
            ans = "No";
            break;
        }
    }
    cout << ans << endl;
}