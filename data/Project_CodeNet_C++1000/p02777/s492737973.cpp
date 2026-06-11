#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s, t, u;
    int a, b;
    cin >> s >> t >> a >> b >> u;
    
    if (u == s) a--;
    else if (u == t) b--;

    printf("%d %d", a, b);
    cout << endl;
    return 0;
}