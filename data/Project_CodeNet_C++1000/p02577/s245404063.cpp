#include<bits/stdc++.h>
using namespace std;

int main () {
    string n;
    cin >> n;

    int a = n.size(), b = 0;
    for (int i = 0; i < a; i++) {
        b += n[i] -'0';
    }
    cout << (b%9 == 0 ? "Yes" : "No") << endl;
}