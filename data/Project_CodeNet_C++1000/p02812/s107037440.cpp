//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


void solve() {
    int N; string s;
    cin >> N >> s;
    int cnt = 0;
    for (int i = 0; i < N-2; i++) {
        if (s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') cnt++;
    }

    cout << cnt << endl;
}


int main() {
    solve();
    return 0;
}