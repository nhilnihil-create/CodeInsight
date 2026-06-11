#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    if (s[0]==s[1] || s[1]==s[2] || s[2]==s[3]) cout << "Bad" << endl;
    else cout << "Good" << endl;
    return 0;
}