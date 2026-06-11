#include <bits/stdc++.h>
using namespace std;
int main() {
    string S,T;cin >> S >> T;
    int t = T.size();
    if (t==S.size()+1 && T==(S+T[t-1])) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}