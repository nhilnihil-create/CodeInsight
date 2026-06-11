#include<bits/stdc++.h>
using namespace std;

int main(void) {
    string S1, S2;
    cin >> S1 >> S2;

    if(S1.length()+1 != S2.length()) {
        cout << "No" << endl;
    } else if(S2.substr(0, S1.length()) == S1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}