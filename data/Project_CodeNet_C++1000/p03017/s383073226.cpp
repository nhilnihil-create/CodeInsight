#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    string S;
    cin >> S;
    bool ikeru = true;
    for (int i=A-1; i<C-1; i++) {
        if (S[i] == '#') {
            continue;
        }

        if (S[i+1] == '#' && S[i+2] == '#') {
            ikeru = false;
            break;
        }

    }

    for (int i=B-1; i<D-1; i++) {
        if (S[i] == '#') {
            continue;
        }

        if (S[i+1] == '#' && S[i+2] == '#') {
            ikeru = false;
            break;
        }

    }

    if (C > D) {
        bool murikamo = true;
        for (int i=B-1; i<D; i++) {
            if (S[i] == '#') {
                continue;
            }

            if (S[i-1] != '#' && S[i+1] != '#') {
                murikamo = false;
                break;
            }
        }

        if (murikamo) {
            ikeru = false;
        }
    }

    if (ikeru) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}