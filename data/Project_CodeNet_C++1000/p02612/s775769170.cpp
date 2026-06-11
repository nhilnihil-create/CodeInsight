#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define ll long long
inline int roundup(int a, int b) { return (((a + (b -1)) / b)); }
using namespace std;

signed main(void) {
    int n;
    cin >> n;
    cout << ((n % 1000 == 0)? 0 : (1000-(n%1000))) << '\n';
    return 0;
}