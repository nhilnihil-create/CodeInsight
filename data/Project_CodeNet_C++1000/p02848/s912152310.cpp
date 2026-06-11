#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0, index = 0;
    cin >> n;
    string s = "", all_alphabet = "";
    cin >> s;
    all_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    for (int i = 0; i < s.size(); i++) {
        index = all_alphabet.find(s.at(i));
        cout << all_alphabet.at((index + n) % 26);
    }
    cout << endl;
}