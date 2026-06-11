#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    for (int i = 0; i < S.size(); i++) {
        int x = S.at(i) - 'A';
        x = (x + N) % 26;
        S.at(i) = 'A' + x;
    }
    cout << S << endl;
}