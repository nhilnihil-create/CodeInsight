#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

bool is_palindrome(string s) {
    string t(s.rbegin(), s.rend());
    return s == t;
}

int main() {

    string S;
    cin >> S;

    int a = (S.size() - 1) / 2;
    int b = (S.size() + 1) / 2;

    if (is_palindrome(S) && is_palindrome(S.substr(0, a)) && is_palindrome(S.substr(b))) {
        cout << "Yes" << endl;

    } else {
        cout << "No" << endl;
    }


    return 0;
}