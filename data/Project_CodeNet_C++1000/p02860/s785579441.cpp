//
// Created by corol

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio();
    cin.tie(0);
    int n;
    cin >>n;
    string a="",b="";
    for (int i=0;i<n/2;i++) {
        char c;
        cin >> c;
        a+=c;
    }
    for (int i=n/2;i<n;i++) {
        char c;
        cin >> c;
        b+=c;
    }
    cout << (a==b ? "Yes" :"No");
    //cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s. \n";
    return 0;
}
