#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    int n, d; cin >> n >> d;
    int manege = d * 2 + 1;
    if(n % manege != 0) cout << n / manege + 1 << endl;
    else cout << n / manege << endl;
    return 0;
}
