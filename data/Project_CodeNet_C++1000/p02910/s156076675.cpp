#include <bits/stdc++.h>
using namespace std;

int main() {
    string ans = "Yes";
    string S;
    cin >> S;
    for(size_t i = 0; i < S.size(); i++) {
        if(i % 2 == 1 && S[i] == 'R')
            ans = "No";
        if(i % 2 == 0 && S[i] == 'L')
            ans = "No";
    }

    cout << ans << endl;
}