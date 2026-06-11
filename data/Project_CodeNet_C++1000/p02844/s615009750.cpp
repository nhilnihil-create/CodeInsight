#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    map<string, bool> A1, A2, A3;

    int N;
    cin >> N;
    string S;
    cin >> S;

    A1[S.substr(N-1, 1)] = true;
    A1[S.substr(N-2, 1)] = true;
    A2[S.substr(N-2)] = true;
    for (int i = N - 3; i >= 0; i--) {
        for (auto const& e : A2) {
            string s = S.substr(i, 1);
            s += e.first;
            A3[s] = true;
        }

        for (auto const& e : A1) {
            string s = S.substr(i, 1);
            s += e.first;
            A2[s] = true;
        }

        A1[S.substr(i, 1)] = true;
    }
    
    cout << A3.size() << endl;
}