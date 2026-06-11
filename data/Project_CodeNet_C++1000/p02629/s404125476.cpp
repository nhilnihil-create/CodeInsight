#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;
    string s = "";
    while (n > 0)
    {
        --n;
        int b = n % 26;
        char c = 'a' + (char)(b);
        s += c;
        n /= 26;
    }
    reverse(ALL(s));
    cout << s << endl;
    return 0;
}