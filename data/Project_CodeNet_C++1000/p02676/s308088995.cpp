#include <bits/stdc++.h>
using namespace std;

int main() {

    int K;
    string S;

    cin >> K >> S;

    if (S.size() <= K) {
        cout << S;
        return 0;
    }

    for (int i = 0; i < K; i++) {
        cout << S.at(i);
    }

    cout << "...";



}