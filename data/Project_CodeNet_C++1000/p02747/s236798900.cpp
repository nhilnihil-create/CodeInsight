#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 100;

int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int t = n/2;
    string ss;
    while(t--) ss += "hi";
    if(s == ss) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}

