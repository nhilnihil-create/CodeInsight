#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int a; cin >> a;
    string s; cin >> s;
    if (a >= 3200) {
        cout << s << endl;
    } else {
        cout << "red" << endl;
    }
}