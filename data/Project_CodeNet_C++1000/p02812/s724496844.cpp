#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int n;
    string s;
    cin >> n >> s;

    int num = 0;
    for (int i = 0; i <= n-3; i++) {
        if (s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') {
            num++;
        }
    }

    cout << num << endl;
    return 0;
}