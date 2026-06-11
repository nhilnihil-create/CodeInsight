#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    string s;
    cin >> n >> s;
    string s1, s2;
    s1 = s.substr(0, s.size()/2);
    s2 = s.substr(s.size()/2, s.size()/2);
    if (s1 != s2 || n % 2 == 1) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}