#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep2(i,x,n) for (int i = x; i < n; i++)
using ll = long long int;
int main() {
    int a,b,c,k; cin >> a >> b >> c >> k;
    if (a >= k) cout << k << endl;
    else if (a+b >= k) cout << a << endl;
    else cout << 2*a+b-k << endl;
    return 0;
}