#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < N; i++)
#define INF (INT64_MAX /2)


























int main() {
    string s;
    cin >> s;
    if (*(s.end() - 1) == 's') {
        cout << s << "es" << endl;
    }
    else cout << s << 's' << endl;
}