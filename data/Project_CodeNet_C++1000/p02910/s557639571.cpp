#include<bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    for (int i=0; i<S.length(); i++) {
        if (i % 2 == 0 && S[i] == 'L') { cout << "No\n"; return 0; }
        else if (i % 2 != 0 && S[i] == 'R') { cout << "No\n"; return 0; }
    }
    cout << "Yes\n";
    return 0;
}
