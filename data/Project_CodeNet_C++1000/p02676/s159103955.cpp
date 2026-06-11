#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
    int k;
    string s;
    cin >> k >> s;

    int a = s.size();
    if (a <= k) {
        cout << s << endl;
    }
    else {
        for (int i = 0; i < k; i++) {
            cout << s[i];
        }
        cout << "..." << endl;
    }
}