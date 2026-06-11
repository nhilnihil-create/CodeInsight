#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long o = 1;
    char c;
    string ans;
    n--;
    while (1) {
        if (n < o && o != 1) break;
        if (o != 1) n -= o;
        c = n % (o*26) / o + 'a';
        ans = c + ans;
        n -= n % (o*26);
        o *= 26;
    }
    cout << ans << endl;
}