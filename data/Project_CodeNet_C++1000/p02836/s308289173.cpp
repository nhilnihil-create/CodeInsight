#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    int count = 0;
    int len = S.size() / 2;
    int l = S.size() - 1;
    for (int i=0; i < len; i++) {
        if (S[i] != S[l - i]) {
            count += 1;
        }
    }

    cout << count << endl;
    return 0;
}