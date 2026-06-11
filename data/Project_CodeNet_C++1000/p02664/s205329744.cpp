#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string T;
    cin >> T;
    for (int i = 0; i < T.size(); i++) {
        if (T[i] == '?') {
            T[i] = 'D';
        }
    }
    cout << T << endl;
}
