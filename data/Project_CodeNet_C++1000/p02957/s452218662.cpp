#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 1; i < n; i++)
typedef long long ll;

int main() {
    int a, b; cin >> a >> b;
    if((a+b)%2==0) cout << (a+b)/2 << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}

