#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)

const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    rep(i,3) {
        if (s[i] == s[i+1]) {
            cout << "Bad" << endl;
            return 0;
        }
    }
    cout << "Good" << endl;
    return 0;
}