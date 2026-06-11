#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
int main() {
    int a, b, c; cin >> a >> b >> c;
    if(c - (a - b) <= 0) cout << '0' << endl;
    else cout << c - (a - b) << endl;
    return 0;
}