#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl

typedef long long LL;

int n, m;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    if(n%2 == 0) n--;

    int l = 1, r = n/2;
    for(int i = 0; i < m/2; ++i) {
        cout << l << ' ' << r << '\n';
        l++; --r;
    }

    l = n/2+1, r = n;
    for(int i = m/2; i < m; ++i) {
        cout << l << ' ' << r << '\n';
        l++; --r;
    }
    
    return 0;
}
