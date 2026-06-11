#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    int n;
    string s;
    cin >> n >> s;
    rep(i, s.size()) {
        if (s[i]+n <= 'Z') putchar(s[i]+n);
        else putchar(s[i]+n-'Z'+'A'-1);
    }
    printf("\n");

    return 0;
}