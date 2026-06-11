#include <bits/stdc++.h>
using namespace std;

int main() {
    string S,T;
    cin >> S >> T;
    if(T.erase((int)S.length()) == S) {
        cout << "Yes" << endl;
    }else {
        cout <<"No" <<endl;
    }
}