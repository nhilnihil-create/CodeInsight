#include <bits/stdc++.h>          
using namespace std;               

int main() {
    string S,T;
    cin >> S;
    cin >> T;
    for (int i=0; i<S.size(); i++) {
        if (S.at(i) != T.at(i)) {
            cout << "No" << endl;
            exit(0);
        }
    }
    cout << "Yes" << endl;
}