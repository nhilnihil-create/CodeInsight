#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s, t, u;
    int a, b;
    cin >> s >> t;
    cin >> a >> b;
    cin >> u;

    if(s == u) {
        a--;
    }
    else if(t == u)
        b--;
    cout << a << " " << b;
    return 0;
}
