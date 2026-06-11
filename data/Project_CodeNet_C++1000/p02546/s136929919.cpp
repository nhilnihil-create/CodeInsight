#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    string S;
    cin >> S;
    if (S.back() == 's') {
        S += "es";
    }
    else {
        S += "s";
    }
    cout << S << endl;
}