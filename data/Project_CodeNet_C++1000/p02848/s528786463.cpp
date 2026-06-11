#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;
    string alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string S;
    cin >> S;
    
    for (int i=0; i<S.size(); i++) {
        for (int j=0; j<26; j++) {
            if (alphabet.at(j)==S.at(i)) {
                cout << alphabet.at((j+N)%26);
            }
        }
    }
    cout << endl;
}
