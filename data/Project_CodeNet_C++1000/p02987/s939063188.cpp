#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

string S;

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> S;
    sort(S.begin(), S.end());
    if (S[0]==S[1] && S[1]!=S[2] && S[2]==S[3]) cout << "Yes" << endl;
    else cout << "No" << endl;
}