#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string S;
    cin >> S;
    map<char,int> m;
    for(int i=0;i<4;i++) {
        m[S[i]]++;
    }

    if((m.size() == 2) && (m.begin()->second == 2)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}
